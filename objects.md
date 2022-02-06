# Objekte

Eine PDF-Datei besteht zum großen Teil aus Objekten. Auch in unserem Beispiel
gibt es bereits 5 Objekte, die 24 Zeilen der Datei ausmachen. Sie bestehen
aus der Eröffnung

```
id 0 obj
```

und enden mit

```
endobj
```

Dabei ist `id` eine laufende Nummer. Die nachfolgende `0` ist eine
Versionsnummer, die zunächst nicht unterstützt wird. Beides können wir in
in eine neue Methode in `mkpdf.h` kapseln:

```c++
// ...
	class Page;
	class Close_Stream {
			std::ostream &out_;
		public:
			Close_Stream(std::ostream &out): out_ { out } { }
			~Close_Stream() { out_ << "endobj\n"; }
			std::ostream &out() const { return out_; }
	};
	inline const Close_Stream &operator<<(const Close_Stream &cs, const std::string &str) {
		cs.out() << str;
		return cs;
	}
	class Pdf {
		// ...
		public:
			Close_Stream create_obj(int id) {
				return Close_Stream { out_ << id << " 0 obj\n" };
			}
		// ...
	};
// ...
```

Damit kann der Destruktor in `mkpdf.cpp` umgeschrieben werden:

```c++
// ...
		// objects
		create_obj(1) << "<</Kids [2 0 R] /Type /Pages /Count 1>>\n";
		create_obj(2) << "<</Resources 3 0 R /Contents [4 0 R] /Parent 1 0 R"
			" /Type /Page /MediaBox [0 0 612 792]>>\n";
		create_obj(3) << "<</Font <</F0 <<"
				"/Subtype /Type1 /Type /Font /BaseFont /Times-Roman"
			">> >> >>\n";
		create_obj(4) << "<<\n"
			"/Length 56\n"
			">>\n"
			"stream\n"
			"BT\n"
				"/F0 12 Tf\n"
				"1 0 0 1 72 720 Tm\n"
				"[(Just some text.)] TJ\n"
			"ET\n"
			"endstream\n";
		create_obj(5) << "<</Type /Catalog /Pages 1 0 R>>\n";
		#if 0
		out_ << "1 0 obj\n"
			// ...
		#endif
// ...
```

Zu jedem Objekt muss nun die Position in der Datei gespeichert werden, an
der dieses Objekt steht. Diese werden am Ende des Dokumentes in der `xref`
Sektion ausgegeben. Hier sind die Anpassungen in `mkpdf.h`:

```c++
// ...
#include <string>
#include <map>
// ...
	class Pdf {
			std::map<int, std::streampos> objs_;
			// ...
		public:
			std::streampos pos() { return out_.tellp(); }
			// ...
			Close_Stream create_obj(int id) {
				objs_.emplace(id, pos());
				// ...
			}
			// ...
	};
// ...
```

Damit kann dann die `xref`-Generierung korrekt in `mkpdf.cpp` ausformuliert
werden:

```c++
// ...
#include "mkpdf.h"
#include <cassert>
#include <iomanip>

// ...
		// xref
		assert(! objs_.empty());
		int max { (--objs_.end())->first };
		out_ << "xref\n0 " << (max + 1) << "\n";
		for (int i { 0 }; i <= max; ++i) {
			auto got { objs_.find(i) };
			if (got != objs_.end()) {
				out_ << std::setw(10) << std::setfill('0') << got->second <<
					" 00000 n \n";
			} else {
				out_ << "0000000000 65535 f \n";
			}
		}
		#if 0
		out_ << "xref\n"
			// ...
		#endif
// ...
```

Wir haben es fast soweit, dass wir uns vom Dummy-PDF lösen können und
Objekte erzeugen können, wie es uns gefällt. Was noch fehlt, ist eine kleine
Anpassung im `trailer`: Hier wird auf die Byte-Position der `xref`
verwiesen. Diese müssen wir ebenfalls dynamisch berechnen:

```c++
// ...
		// xref
		auto xref_pos { pos() };
		// ...

		// trailer
		out_ << "trailer\n"
			"<</Root 5 0 R /Size " << (max + 1) << ">>\n"
			"startxref\n"
			<< xref_pos << "\n"
			"%%EOF\n";
		#if 0
			// ...
		#endif
// ...
```

Die Referenz auf das Root-Objekt können wir im nächsten Teil anpassen:
In [structure.md](./structure.md) geht es um die allgemeine
Dokumentenstruktur.
