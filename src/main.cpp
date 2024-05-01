#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/ItemInfoPopup.hpp>
#include <Geode/modify/GJGarageLayer.hpp>
#include <Geode/modify/GameManager.hpp>

using namespace geode::prelude;

#define DEFAULT_CUBE 484
#define DEFAULT_SHiP 169
#define DEFAULT_BALL 118
#define DEFAULT_UFO 149
#define DEFAULT_WAVE 96
#define DEFAULT_ROBOT 68
#define DEFAULT_SPIDER 69
#define DEFAULT_SWING 43
#define DEFAULT_JETPACK 5

int cubeCount = 0;
int shipCount = 0;
int ballCount = 0;
int ufoCount = 0;
int waveCount = 0;
int robotCount = 0;
int spiderCount = 0;
int swingCount = 0;
int jetpackCount = 0;

void updateCounts()
{
	cubeCount = Mod::get()->getSettingValue<int64_t>("cube-count");
	shipCount = Mod::get()->getSettingValue<int64_t>("ship-count");
	ballCount = Mod::get()->getSettingValue<int64_t>("ball-count");
	ufoCount = Mod::get()->getSettingValue<int64_t>("ufo-count");
	waveCount = Mod::get()->getSettingValue<int64_t>("wave-count");
	robotCount = Mod::get()->getSettingValue<int64_t>("robot-count");
	spiderCount = Mod::get()->getSettingValue<int64_t>("spider-count");
	swingCount = Mod::get()->getSettingValue<int64_t>("swing-count");
	jetpackCount = Mod::get()->getSettingValue<int64_t>("jetpack-count");
}

$execute {
	updateCounts();
}

class $modify (GameManager)
{
	static int countForType(IconType p0)
	{
		updateCounts();

		if (p0 == IconType::Cube)
			return cubeCount;

		if (p0 == IconType::Ship)
			return shipCount;

		if (p0 == IconType::Ball)
			return ballCount;

		if (p0 == IconType::Ufo)
			return ufoCount;

		if (p0 == IconType::Wave)
			return waveCount;

		if (p0 == IconType::Robot)
			return robotCount;

		if (p0 == IconType::Spider)
			return spiderCount;

		if (p0 == IconType::Swing)
			return swingCount;

		if (p0 == IconType::Jetpack)
			return jetpackCount;

		return GameManager::countForType(p0);
	}

	bool isIconUnlocked(int p0, IconType p1)
	{
		if (p1 == IconType::Cube && p0 > DEFAULT_CUBE)
			return true;

		if (p1 == IconType::Ship && p0 > DEFAULT_SHiP)
			return true;

		if (p1 == IconType::Ball && p0 > DEFAULT_BALL)
			return true;

		if (p1 == IconType::Ufo && p0 > DEFAULT_UFO)
			return true;

		if (p1 == IconType::Wave && p0 > DEFAULT_WAVE)
			return true;

		if (p1 == IconType::Robot && p0 > DEFAULT_ROBOT)
			return true;

		if (p1 == IconType::Spider && p0 > DEFAULT_SPIDER)
			return true;

		if (p1 == IconType::Swing && p0 > DEFAULT_SWING)
			return true;

		if (p1 == IconType::Jetpack && p0 > DEFAULT_JETPACK)
			return true;

		return GameManager::isIconUnlocked(p0, p1);
	}
};

class $modify (ItemInfoPopup)
{
	bool init(int p0, UnlockType p1)
	{
		if (!ItemInfoPopup::init(p0, p1))
			return false;

		auto lbl = getChildOfType<TextArea>(m_mainLayer, 0);
		auto title = getChildOfType<CCLabelBMFont>(m_mainLayer, -1);

		if (!lbl || !title)
			return true;

		if (p1 == UnlockType::Cube && p0 > DEFAULT_CUBE)
		{
			title->setString("Custom Cube");
			lbl->setString("This <cg>Cube</c> has been added by a <cl>texture pack</c>.");
		}

		if (p1 == UnlockType::Ship && p0 > DEFAULT_SHiP)
		{
			title->setString("Custom Ship");
			lbl->setString("This <cg>Ship</c> has been added by a <cl>texture pack</c>.");
		}

		if (p1 == UnlockType::Ball && p0 > DEFAULT_BALL)
		{
			title->setString("Custom Ball");
			lbl->setString("This <cg>Ball</c> has been added by a <cl>texture pack</c>.");
		}

		if (p1 == UnlockType::Bird && p0 > DEFAULT_UFO)
		{
			title->setString("Custom Ufo");
			lbl->setString("This <cg>Ufo</c> has been added by a <cl>texture pack</c>.");
		}

		if (p1 == UnlockType::Dart && p0 > DEFAULT_WAVE)
		{
			title->setString("Custom Wave");
			lbl->setString("This <cg>Wave</c> has been added by a <cl>texture pack</c>.");
		}

		if (p1 == UnlockType::Robot && p0 > DEFAULT_ROBOT)
		{
			title->setString("Custom Robot");
			lbl->setString("This <cg>Robot</c> has been added by a <cl>texture pack</c>.");
		}

		if (p1 == UnlockType::Robot && p0 > DEFAULT_SPIDER)
		{
			title->setString("Custom Spider");
			lbl->setString("This <cg>Spider</c> has been added by a <cl>texture pack</c>.");
		}

		if (p1 == UnlockType::Robot && p0 > DEFAULT_SPIDER)
		{
			title->setString("Custom Swing");
			lbl->setString("This <cg>Swing</c> has been added by a <cl>texture pack</c>.");
		}

		if (p1 == UnlockType::Jetpack && p0 > DEFAULT_JETPACK)
		{
			title->setString("Custom Jetpack");
			lbl->setString("This <cg>Jetpack</c> has been added by a <cl>texture pack</c>.");
		}


		return true;
	}
};