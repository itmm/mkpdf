#line 13 "README.md"
#include "mkpdf.h"

#include <fstream>

int main() {
	// test-cases
	{
		std::ofstream first { "first.pdf" };
		Mk_Pdf::Pdf pdf { first };
		auto page { pdf.append_page() };
		page.move_to(240, 330);
		page.draw_string("Just some text.");
	}
}
