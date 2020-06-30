/* Exercise 6.9 on p. 208 */
#include "Chapter6.h"

int getFact(int x) {
	int ret = 1;
	while (x > 1) {
		ret *= x--;
	}
	return ret;
}