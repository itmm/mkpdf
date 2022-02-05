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
			Pdf(std::ostream &out): out_ { out } {
#line 104 "./first_fake.md"
				write_header();
#line 50 "README.md"
			}
#line 106 "./first_fake.md"
			void write_header() {
				out_ << "%PDF-1.0\n"
					"%\xe2\xe3\xcf\xd3\n";
			}
#line 51 "README.md"
			Page append_page();
	};
	class Page {
		public:
			void move_to(int x, int y);
			void draw_string(const std::string &str);
	};
}
