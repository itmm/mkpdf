#line 65 "README.md"
#include "mkpdf.h"

namespace Mk_Pdf {
#line 27 "./first_fake.md"
	Pdf::~Pdf() {
		// header
#line 122
		#if 0
#line 29
		out_ << "%PDF-1.0\n"
			"%\xe2\xe3\xcf\xd3\n";
#line 125
		#endif
#line 31

		// objects
		out_ << "1 0 obj\n"
			"<</Kids [2 0 R] /Type /Pages /Count 1>>\n"
			"endobj\n"
			"2 0 obj\n"
			"<</Resources 3 0 R /Contents [4 0 R] /Parent 1 0 R"
				" /Type /Page /MediaBox [0 0 612 792]>>\n"
			"endobj\n"
			"3 0 obj\n"
			"<</Font <</F0 <<"
				"/Subtype /Type1 /Type /Font /BaseFont /Times-Roman"
			">> >> >>\n"
			"endobj\n"
			"4 0 obj\n"
			"<<\n"
			"/Length 56\n"
			">>\n"
			"stream\n"
			"BT\n"
				"/F0 12 Tf\n"
				"1 0 0 1 72 720 Tm\n"
				"[(Just some text.)] TJ\n"
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
			"0000000370 00000 n \n";

		// trailer
		out_ << "trailer\n"
			"<</Root 5 0 R /Size 6>>\n"
			"startxref\n"
			"417\n"
			"%%EOF\n";
	}
#line 68 "README.md"
	Page Pdf::append_page() { return Page { }; }
	void Page::move_to(int x, int y) { }
	void Page::draw_string(const std::string &str) { }
}
