
/*		Domaci 1
 *
 *	Kod je pisan sa tab width = 4
 *	
 *	-std=c++20
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

class Array
{
	public:
		vector<int> n;
		map<int, int> br_stanje;

		void get(void) {
			int tmp;
			cout <<	"Unesite elemente niza.\n"
					"Za prekid unosa niza unesite:\n"
					"\tUnix:\t\tControl + D\n"
					"\tWindows:\tControl + Z\n\n";
			while (cin >> tmp) {
				n.push_back(tmp);
			}
			return;
		}

		void print(void) {
			cout << "\nniz: ";
			for (int i : n) {
				cout << i << ' ';
			}
			cout << endl;
			return;
		}
		
		int max(void) {
			int tmp = n[0];

			for (int i : n) {
				if (i > tmp) {
					tmp = i;
				}
			}
			return tmp;
		}

		void max_ponavljanja(void) {
			int tmp_ponavljanje, tmp_broj;

			tmp_ponavljanje = 1;
			tmp_broj = n[0];

			for (const auto& [broj_niza, broj_ponavljanja] : br_stanje) {
				if (broj_ponavljanja > tmp_ponavljanje) {
					tmp_ponavljanje = broj_ponavljanja;
					tmp_broj = broj_niza;
				}
			}

			if (tmp_ponavljanje == 1) {
				cout << "Svi brojevi su ravnomerno zastupljeni." << endl;
			} else {
				cout	<< "Broj " << tmp_broj
						<< " je najzastupljeniji u nizu, javlja se "
						<< tmp_ponavljanje << " puta." << endl;
			}
			return;
		}

		void prebroj(void) {
			for (int i : n) {
				if (br_stanje.contains(i)) {
					++br_stanje[i];
				} else {
					br_stanje.insert({i,1});
				}
			}
			return;
		}

		void raspodela(void) {
			for (const auto& [broj_niza, broj_ponavljanja] : br_stanje) {
				cout << '\t' << broj_niza << "\t--\t" << broj_ponavljanja << endl;
			}
			return;
		}
};

int
main(void)
{
	Array niz;
	niz.get();
	niz.print();
	cout << "Element maksimalne vrednosti = " << niz.max() << endl;
	niz.prebroj();
	niz.raspodela();
	niz.max_ponavljanja();
	return 0;
}
