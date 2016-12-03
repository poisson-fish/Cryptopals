// This is the main DLL file.

#include "stdafx.h"

#include "cryptopals.h"
using namespace Cryptopals;

char * Basic::hexToBase64(char* hex) {
	if (hex) {
		bool reading;
		int index;
		int base;
		while (reading) {
			if (hex[index] == '\0') { reading = false; break; }

			index++;
		}
	}
	else {
		return nullptr;
	}
}