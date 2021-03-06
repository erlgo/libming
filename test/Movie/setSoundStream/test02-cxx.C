#include <mingpp.h>
#include <cstdlib>
#include <cstdio>

int main()
{
	try {
		SWFMovie *m = new SWFMovie(7);
		SWFSoundStream *stream;
		int i;
		FILE *file;

		file = fopen(MEDIADIR "/video02.flv", "rb");
		if(!file) {
			return EXIT_FAILURE;
		}

		stream = new SWFSoundStream(file);
		m->setSoundStream(stream);
		for(i = 0; i < 200; i++)
			m->nextFrame();

		m->save("test02.swf");
	}
	catch(SWFException &e)
	{
		std::cerr << "SWFException: " << e.what() << std::endl << std::endl;
		return EXIT_FAILURE;
	}

	return 0;
}
