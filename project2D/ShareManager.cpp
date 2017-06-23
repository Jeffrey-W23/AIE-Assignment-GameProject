//#include, using etc
#include "ShareManager.h"
#include "ResourceManager.h"

ShareManager* ShareManager::m_instance = nullptr;

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
ShareManager::ShareManager()
{
	ResourceManager<Audio>* pAudioManager = ResourceManager<Audio>::GetInstance();

	m_audio["menu"] = pAudioManager->LoadResource("./audio/menu.ogg");
	m_audio["menu2"] = pAudioManager->LoadResource("./audio/menu.ogg");
	m_audio["chime"] = pAudioManager->LoadResource("./audio/teamchime.ogg");
	m_audio["enter"] = pAudioManager->LoadResource("./audio/enter.ogg");
	m_audio["select"] = pAudioManager->LoadResource("./audio/select.ogg");
	m_audio["back"] = pAudioManager->LoadResource("./audio/back.ogg");

	quitBool = false;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
ShareManager::~ShareManager()
{
}

ShareManager* ShareManager::Instance()
{
	return m_instance;
}

void ShareManager::Quit(bool quit)
{
	quitBool = quit;
}

bool ShareManager::QuitCheck()
{
	return quitBool;
}

int ShareManager::PlayAudio(char* song)
{
	// return a error code here for if the "song" var is incorrect
	// also put an assert here.
	// put an Assert on the return as well

	m_audio[song]->play();

	return 0;
}

int ShareManager::StopAudio(char* song)
{
	m_audio[song]->stop();

	return 0;
}

int ShareManager::StopAllAudio()
{
	for (int i = 0; i < m_audio.Size(); ++i)
	{
		m_audio[i]->stop();
	}

	return 0;
}

int ShareManager::SetAudioLoop(char* song, bool loop)
{
	m_audio[song]->setLooping(loop);

	return 0;
}