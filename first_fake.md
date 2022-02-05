# PDF-Ausgabe ermogeln

Wir nehmen für den Anfang eine fertige PDF-Datei. Im Destruktor von `Pdf`
geben wir diese aus. Damit haben wir eine gute Ausgangsbasis, um weitere
Schritte in vivo zu implementieren.

Zunächst muss in `mkpdf.h` der Destruktor der Klasse deklariert werden:

```c++
// ...
	class Pdf {
		// ...
		public:
			~Pdf();
		// ...
	};
// ...
```

Und in diesem Destruktor geben wir in `mkpdf.cpp` das ganze Dokument aus.
Mit Kommentaren werden aber schon die einzelnen Blöcke der Datei markiert,
so dass sie später leicht ausgetauscht werden können:

```c++
// ...
namespace Mk_Pdf {
	Pdf::~Pdf() {
		// header
		out_ << "%PDF-1.0\n"
			"%\xe2\xe3\xcf\xd3\n";

		// objects
		out_ << "1 0 obj\n"
			"<</Kids [2 0 R] /Type /Pages /Count 1>>\n"
			"endobj\n"
			"2 0 obj\n"
			"<</Resources 3 0 R /Contents [4 0 R] /Parent 1 0 R /Type /Page /MediaBox [0 0 612 792]>>\n"
			"endobj\n"
			"3 0 obj\n"
			"<</Font <</F0 <</Subtype /Type1 /Type /Font /BaseFont /Times-Roman>> >> >>\n"
			"endobj\n"
			"4 0 obj\n"
			"<<\n"
			"/Length 59\n"
			">>\n"
			"stream\n"
			"BT\n"
			"	/F0 12 Tf\n"
			"	1 0 0 1 72 720 Tm\n"
			"	[(Just some text.)] TJ\n"
			"ET\n"
			"endstream\n"
			"endobj\n"
			"5 0 obj\n"
			"<</Type /Catalog /Pages 1 0 R>>\n"
			"endobj\n";

		// xref
		out_ << "xref\n"
			"0 6\n"
			"0000000000 65535 f \n"
			"0000000015 00000 n \n"
			"0000000070 00000 n \n"
			"0000000174 00000 n \n"
			"0000000264 00000 n \n"
			"0000000373 00000 n \n";

		// trailer
		out_ << "trailer\n"
			"<</Root 5 0 R /Size 6>>\n"
			"startxref\n"
			"420\n"
			"%%EOF\n";
	}
	// ...
}
```
