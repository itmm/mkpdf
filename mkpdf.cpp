#line 65 "README.md"
#include "mkpdf.h"
#line 105 "./objects.md"
#include <cassert>
#include <iomanip>
#line 66 "README.md"

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
#line 51 "./objects.md"
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
#line 33 "./first_fake.md"
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
#line 71 "./objects.md"
		#endif
#line 60 "./first_fake.md"

		// xref
#line 137 "./objects.md"
		auto xref_pos { pos() };
#line 110
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
#line 62 "./first_fake.md"
		out_ << "xref\n"
			"0 6\n"
			"0000000000 65535 f \n"
			"0000000015 00000 n \n"
			"0000000070 00000 n \n"
			"0000000174 00000 n \n"
			"0000000264 00000 n \n"
			"0000000370 00000 n \n";
#line 125 "./objects.md"
		#endif
#line 70 "./first_fake.md"

		// trailer
		out_ << "trailer\n"
#line 142 "./objects.md"
			"<</Root 5 0 R /Size " << (max + 1) << ">>\n"
			"startxref\n"
			<< xref_pos << "\n"
			"%%EOF\n";
		#if 0
#line 73 "./first_fake.md"
			"<</Root 5 0 R /Size 6>>\n"
			"startxref\n"
			"417\n"
			"%%EOF\n";
#line 148 "./objects.md"
		#endif
#line 77 "./first_fake.md"
	}
#line 68 "README.md"
	Page Pdf::append_page() { return Page { }; }
	void Page::move_to(int x, int y) { }
	void Page::draw_string(const std::string &str) { }
}
