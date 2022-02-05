#line 39 "README.md"
#pragma once

#include <ostream>
#include <string>

namespace Mk_Pdf {
	class Page;
	class Pdf {
			std::ostream &out_;
		public:
#line 14 "./first_fake.md"
			~Pdf();
#line 49 "README.md"
			Pdf(std::ostream &out): out_ { out } { }
			Page append_page();
	};
	class Page {
		public:
			void move_to(int x, int y);
			void draw_string(const std::string &str);
	};
}
