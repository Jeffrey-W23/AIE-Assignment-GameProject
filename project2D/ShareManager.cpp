//#include, using etc
#include "ShareManager.h"
#include "ResourceManager.h"

//--------------------------------------------------------------------------------------
// The one and only instance of this class
//--------------------------------------------------------------------------------------
ShareManager* ShareManager::m_instance = nullptr;

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
ShareManager::ShareManager()
{
	// Get a new instance of the resource manager.
	ResourceManager<Audio>* pAudioManager = ResourceManager<Audio>::GetInstance();

	//load all the audio files in the Associative Array.
	m_audio["menu"] = pAudioManager->LoadResource("./audio/menu.ogg");
	m_audio["menu2"] = pAudioManager->LoadResource("./audio/menu.ogg");
	m_audio["chime"] = pAudioManager->LoadResource("./audio/teamchime.ogg");
	m_audio["enter"] = pAudioManager->LoadResource("./audio/enter.ogg");
	m_audio["select"] = pAudioManager->LoadResource("./audio/select.ogg");
	m_audio["back"] = pAudioManager->LoadResource("./audio/back.ogg");

	// Initialize vars
	quitBool = false;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
ShareManager::~ShareManager()
{
}

//--------------------------------------------------------------------------------------
// Instance: The function for providing access.
//--------------------------------------------------------------------------------------
ShareManager* ShareManager::Instance()
{
	return m_instance;
}

//--------------------------------------------------------------------------------------
// Quit: A function for telling the game to quit.
//
// Param:
//		quit: a bool for telling the game to quit or not.
//--------------------------------------------------------------------------------------
void ShareManager::Quit(bool quit)
{
	quitBool = quit;
}

//--------------------------------------------------------------------------------------
// QuitCheck: A function to check if the game has been told to quit.
//
// Return:
//		bool: Returns if quit is true or not.
//--------------------------------------------------------------------------------------
bool ShareManager::QuitCheck()
{
	return quitBool;
}

//--------------------------------------------------------------------------------------
// PlayAudio: A function to play a selected piece of audio.
//
// Param:
//		song: a char pointer for the song title that you want to play.
//
// Return:
//		int: An error code.
//--------------------------------------------------------------------------------------
int ShareManager::PlayAudio(char* song)
{
	_ASSERT(song);

	m_audio[song]->play();

	return 0;
}

//--------------------------------------------------------------------------------------
// StopAudio: A function to stop a selected piece of audio.
//
// Param:
//		song: A char pointer for the song title that you want to stop playing.
//
// Return:
//		int: An error code.
//--------------------------------------------------------------------------------------
int ShareManager::StopAudio(char* song)
{
	_ASSERT(song);

	m_audio[song]->stop();

	return 0;
}

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
int ShareManager::StopAllAudio()
{
	for (int i = 0; i < m_audio.Size(); ++i)
	{
		m_audio[i]->stop();
	}

	return 0;
}

//--------------------------------------------------------------------------------------
// StopAllAudio: A function to stop all audio from playing.
//
// Return:
//		int:  An error code.
//--------------------------------------------------------------------------------------
int ShareManager::SetAudioLoop(char* song, bool loop)
{
	_ASSERT(song);

	m_audio[song]->setLooping(loop);

	return 0;
}