#line 74 "README.md"
#include "mkpdf.h"

namespace Mk_Pdf {
	Page Pdf::append_page() { return Page { }; }
	Frame Page::append_frame(const Rect &rect) { return Frame { }; }
	Rect Page::bounds() const { return Rect { }; }
	void Frame::append_paragraph(const std::string &text) { }
}
