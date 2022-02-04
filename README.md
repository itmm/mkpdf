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
		auto frame { page.append_frame(page.bounds()) };
		frame.append_paragraph("Just some text.");
	}
}
```

Ein `Pdf` Dokument serialisiert sich direkt in einen `std::ostream`. Daher
muss dieser gleich im Konstruktor mit angegeben werden. Weiterhin kann ein
`Pdf` Dokument Seiten enthalten. Es gibt maximal eine aktuelle Seite, deren
Inhalt gerade generiert wird.

Auf den Seiten kann es Rahmen geben. Auf der aktuellen Seite gibt es
maximal einen aktuellen Rahmen, in den Text und Bilder eingesetzt werden
können.

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
	class Frame;
	class Rect {};
	class Page {
		public:
			Frame append_frame(const Rect &);
			Rect bounds() const;
	};
	class Frame {
		public:
			void append_paragraph(const std::string &text);
	};
}
```

Und für die Methoden werden erst einmal leere Implementierungen in der Datei
`mkpdf.cpp` vorgesehen, damit das Projekt baut:

```c++
#include "mkpdf.h"

namespace Mk_Pdf {
	Page Pdf::append_page() { return Page { }; }
	Frame Page::append_frame(const Rect &rect) { return Frame { }; }
	Rect Page::bounds() const { return Rect { }; }
	void Frame::append_paragraph(const std::string &text) { }
}
```
