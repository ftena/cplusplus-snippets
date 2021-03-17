#include <iostream>
#include <libintl.h>

#define PACKAGE "test_i18n"
#define LOCALEDIR "./"

int main(int argc, char *argv[])
{

	setlocale (LC_ALL, "");
  bindtextdomain (PACKAGE, LOCALEDIR);
  textdomain (PACKAGE);

printf( "msg: \"%s\".\n", gettext( "starting a new test" ) );
  printf( "msg: \"%s\".\n", gettext( "testing i18n" ) );

	return 0;
}
