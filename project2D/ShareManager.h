//#include, using etc
#pragma once
#include "Audio.h"
#include "AssociativeArray.h"
using namespace aie;

//--------------------------------------------------------------------------------------
// ShareManager object.
//--------------------------------------------------------------------------------------
class ShareManager
{
private:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	ShareManager();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~ShareManager();

	static ShareManager* m_instance;
	
	AssociativeArray<Audio*> m_audio;
	bool quitBool;

public:

	static void create() { m_instance = new ShareManager(); }
	static void destroy() { delete m_instance; }

	static ShareManager* Instance();
	
	void Quit(bool quit);
	bool QuitCheck();
	int PlayAudio(char* song);
	int StopAudio(char* song);
	int SetAudioLoop(char* song, bool loop);
	int StopAllAudio();
};

