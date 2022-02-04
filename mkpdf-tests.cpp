#line 13 "README.md"
#include "mkpdf.h"

#include <fstream>

int main() {
	// test-cases
	{
		std::ofstream first { "first.pdf" };
		Mk_Pdf::Pdf pdf { first };
		auto page { pdf.append_page() };
		auto frame { page.append_frame(page.bounds()) };
		frame.append_paragraph("Just some text.");
	}
}
