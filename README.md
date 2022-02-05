# `mkpdf` PDF-Dokumente erzeugen

Mit dieser Bibliothek versuche ich einfach PDF-Dokumente zu erzeugen.
Dies soll funktionieren, ohne dass ein externes Programm verwendet werden
muss. Vielmehr soll es ein einfacher und schneller Weg sein, um aus anderen
Programmen heraus PDF-Dokumente zu erzeugen.

Eine spezielle Test-Suite `mkpdf-tests.cpp` soll die Verwendung dokumentieren
und gleichzeitig die notwendigen Unit-Tests bilden. Fangen wir mit einem
einfachen Test an:

```c++
#include "mkpdf.h"

#include <fstream>

int main() {
	// test-cases
	{
		std::ofstream first { "first.pdf" };
		Mk_Pdf::Pdf pdf { first };
		auto page { pdf.append_page() };
		page.move_to(240, 330);
		page.draw_string("Just some text.");
	}
}
```

Ein `Pdf` Dokument serialisiert sich direkt in einen `std::ostream`. Daher
muss dieser gleich im Konstruktor mit angegeben werden. Weiterhin kann ein
`Pdf` Dokument Seiten enthalten. Es gibt maximal eine aktuelle Seite, deren
Inhalt gerade generiert wird.

Damit das Beispiel übersetzt, muss es erst einmal eine Datei `mkpdf.h`
geben. Diese muss zumindest die bisher verwendeten Klassen und Methoden
verwenden:

```c++
#pragma once

#include <ostream>
#include <string>

namespace Mk_Pdf {
	class Page;
	class Pdf {
			std::ostream &out_;
		public:
			Pdf(std::ostream &out): out_ { out } { }
			Page append_page();
	};
	class Page {
		public:
			void move_to(int x, int y);
			void draw_string(const std::string &str);
	};
}
```

Und für die Methoden werden erst einmal leere Implementierungen in der Datei
`mkpdf.cpp` vorgesehen, damit das Projekt baut:

```c++
#include "mkpdf.h"

namespace Mk_Pdf {
	Page Pdf::append_page() { return Page { }; }
	void Page::move_to(int x, int y) { }
	void Page::draw_string(const std::string &str) { }
}
```

Nun kann das Beispiel zwar übersetzt werden, aber es entsteht eine leere
Datei. Dies ist keine legale Datei. Der nächste Schritt ist es nun, ein
legales PDF-Dokument zu produzieren.

Dazu ziehen wir das Pferd von hinten
auf. Im Destruktor von `Pdf` erzeugen wir erst einmal ein statisches
PDF-Dokument. Dieses schieben wir dann schrittweise in die einzelnen
Methoden.

Dieser Teil wird in [first_fake.md](./first_fake.md) beschrieben.

