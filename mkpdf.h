#line 39 "README.md"
#pragma once

#include <ostream>
#include <string>
#line 82 "objects.md"
#include <map>
#line 43 "README.md"

namespace Mk_Pdf {
	class Page;
#line 24 "objects.md"
	class Close_Stream {
			std::ostream &out_;
		public:
			Close_Stream(std::ostream &out): out_ { out } { }
			~Close_Stream() { out_ << "endobj\n"; }
			std::ostream &out() const { return out_; }
	};
	inline const Close_Stream &operator<<(const Close_Stream &cs, const std::string &str) {
		cs.out() << str;
		return cs;
	}
#line 46 "README.md"
	class Pdf {
#line 85 "objects.md"
			std::map<int, std::streampos> objs_;
#line 47 "README.md"
			std::ostream &out_;
		public:
#line 88 "objects.md"
			std::streampos pos() { return out_.tellp(); }
#line 38
			Close_Stream create_obj(int id) {
#line 91
				objs_.emplace(id, pos());
#line 39
				return Close_Stream { out_ << id << " 0 obj\n" };
			}
#line 14 "first_fake.md"
			~Pdf();
#line 49 "README.md"
			Pdf(std::ostream &out): out_ { out } {
#line 104 "first_fake.md"
				write_header();
#line 50 "README.md"
			}
#line 106 "first_fake.md"
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
