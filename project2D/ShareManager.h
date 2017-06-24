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

	//--------------------------------------------------------------------------------------
	// The one and only instance of this class
	//--------------------------------------------------------------------------------------
	static ShareManager* m_instance;
	
	//--------------------------------------------------------------------------------------
	// An AssociativeArray of Audio pointers m_audio.
	//--------------------------------------------------------------------------------------
	AssociativeArray<Audio*> m_audio;

	//--------------------------------------------------------------------------------------
	// A bool quitBool for checking if quit button has been pressed.
	//--------------------------------------------------------------------------------------
	bool quitBool;

public:

	//--------------------------------------------------------------------------------------
	// create: A function for creating an instance of the Share manager.
	//--------------------------------------------------------------------------------------
	static void create() { m_instance = new ShareManager(); }

	//--------------------------------------------------------------------------------------
	// destroy: A function for deleting the Share manager instance.
	//--------------------------------------------------------------------------------------
	static void destroy() { delete m_instance; }

	//--------------------------------------------------------------------------------------
	// Instance: The function for providing access.
	//--------------------------------------------------------------------------------------
	static ShareManager* Instance();
	
	//--------------------------------------------------------------------------------------
	// Quit: A function for telling the game to quit.
	//
	// Param:
	//		quit: a bool for telling the game to quit or not.
	//--------------------------------------------------------------------------------------
	void Quit(bool quit);

	//--------------------------------------------------------------------------------------
	// QuitCheck: A function to check if the game has been told to quit.
	//
	// Return:
	//		bool: Returns if quit is true or not.
	//--------------------------------------------------------------------------------------
	bool QuitCheck();

	//--------------------------------------------------------------------------------------
	// PlayAudio: A function to play a selected piece of audio.
	//
	// Param:
	//		song: a char pointer for the song title that you want to play.
	//
	// Return:
	//		int: An error code.
	//--------------------------------------------------------------------------------------
	int PlayAudio(char* song);

	//--------------------------------------------------------------------------------------
	// StopAudio: A function to stop a selected piece of audio.
	//
	// Param:
	//		song: A char pointer for the song title that you want to stop playing.
	//
	// Return:
	//		int: An error code.
	//--------------------------------------------------------------------------------------
	int StopAudio(char* song);

	//--------------------------------------------------------------------------------------
	// SetAudioLoop: A function to set a selected piece of audio to loop.
	//
	// Param:
	//		song: A char pointer for the song title that you want to loop.
	//		loop: A bool to start or stopping an audio from looping.
	//
	// Return:
	//		int:  An error code.
	//--------------------------------------------------------------------------------------
	int SetAudioLoop(char* song, bool loop);

	//--------------------------------------------------------------------------------------
	// StopAllAudio: A function to stop all audio from playing.
	//
	// Return:
	//		int:  An error code.
	//--------------------------------------------------------------------------------------
	int StopAllAudio();
};

