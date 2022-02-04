#line 43 "README.md"
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
