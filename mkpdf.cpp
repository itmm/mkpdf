#line 65 "README.md"
#include "mkpdf.h"
#line 105 "objects.md"
#include <cassert>
#include <iomanip>
#line 66 "README.md"

namespace Mk_Pdf {
#line 27 "first_fake.md"
	Pdf::~Pdf() {
		// header
#line 31

		// objects
#line 51 "objects.md"
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
#line 60 "first_fake.md"

		// xref
#line 137 "objects.md"
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
#line 70 "first_fake.md"

		// trailer
		out_ << "trailer\n"
#line 142 "objects.md"
			"<</Root 5 0 R /Size " << (max + 1) << ">>\n"
			"startxref\n"
			<< xref_pos << "\n"
			"%%EOF\n";
#line 77 "first_fake.md"
	}
#line 68 "README.md"
	Page Pdf::append_page() { return Page { }; }
	void Page::move_to(int x, int y) { }
	void Page::draw_string(const std::string &str) { }
}
