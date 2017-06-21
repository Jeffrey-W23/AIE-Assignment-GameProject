#include "Pause.h"
#include "Input.h"
#include "font.h"
#include "StateMachine.h"

Pause::Pause()
{
	m_font = new Font("./font/PressStart.ttf", 45);
	m_font2 = new Font("./font/PressStart.ttf", 32);
	m_selectorPos = 0;
}

Pause::~Pause()
{

}

void Pause::onEnter(StateMachine* pMachine)
{
	m_selectorPos = 444;
}

void Pause::onUpdate(float deltaTime, StateMachine* pMachine)
{
	Input* input = Input::getInstance();

	if (input->wasKeyPressed(INPUT_KEY_ESCAPE))
	{
		pMachine->SetBackgroundUpdate(false);
		pMachine->PopState();
	}

	if (input->wasKeyPressed(INPUT_KEY_W) && m_selectorPos < 444 || input->wasKeyPressed(INPUT_KEY_UP) && m_selectorPos < 444)
		m_selectorPos += 60;

	if (input->wasKeyPressed(INPUT_KEY_S) && m_selectorPos > 384 || input->wasKeyPressed(INPUT_KEY_DOWN) && m_selectorPos > 384)
		m_selectorPos -= 60;

	if (input->wasKeyPressed(INPUT_KEY_ENTER) && m_selectorPos == 444 || input->wasKeyPressed(INPUT_KEY_SPACE) && m_selectorPos == 444)
	{
		pMachine->SetBackgroundUpdate(false);
		pMachine->PopState();
	}

	if (input->wasKeyPressed(INPUT_KEY_ENTER) && m_selectorPos == 384 || input->wasKeyPressed(INPUT_KEY_SPACE) && m_selectorPos == 384)
	{
		pMachine->SetBackgroundUpdate(false);
		pMachine->PopAll();
		pMachine->PushState(1);
	}
}

void Pause::onDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(0, 0, 0, 0.8);
	m_2dRenderer->drawSprite(nullptr, 0, 0, 1280, 720, 0, 0, 0);

	m_2dRenderer->setRenderColour(0.627f, 0.184f, 0, 1);
	m_2dRenderer->drawText(m_font, "PAUSED!", 493, 525);

	m_2dRenderer->setRenderColour(0.627f, 0.184f, 0, 1);
	m_2dRenderer->drawText(m_font2, "RESUME", 549, 425);
	m_2dRenderer->drawText(m_font2, "MENU", 575, 365);

	m_2dRenderer->setRenderColour(0.627f, 0.184f, 0, 1);
	m_2dRenderer->drawBox(490, m_selectorPos, 28, 28);
}

void Pause::onExit(StateMachine* pMachine)
{

}