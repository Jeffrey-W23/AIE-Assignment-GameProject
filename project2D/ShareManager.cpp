#include "ShareManager.h"
#include "ResourceManager.h"

ShareManager* ShareManager::m_instance = nullptr;

ShareManager::ShareManager()
{
	ResourceManager<Audio>* pAudioManager = ResourceManager<Audio>::GetInstance();

	m_audio["Menu"] = pAudioManager->LoadResource("./audio/menu.ogg");
	m_audio["Menu2"] = pAudioManager->LoadResource("./audio/menu.ogg");

	quitBool = false;
}

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