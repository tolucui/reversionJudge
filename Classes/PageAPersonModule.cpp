#include "PageAPersonModule.h"
#include "LayerMainPageA.h"

PageAPersonModule::PageAPersonModule()
{
}


PageAPersonModule::~PageAPersonModule()
{
	removeAllChildren();
}

bool PageAPersonModule::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	this->setAnchorPoint(Vec2(0, 1));
	this->setTextureRect(Rect(0, FRAMESIZE.height / 3, FRAMESIZE.width, PERSON_MODULE_BOTTOM - BARHIGHT));
	this->setPosition(Vec2(0, FRAMESIZE.height - BARHIGHT));
	this->setOpacity(0);

	std::string  headPath= PERSONHEAD_PICPATH;
	headPath.append(PersonName_other[1]);
	headPath.append(PIC);

	personHead = PersonHead::create(headPath, PERSONHEADHEIGHT_OWN);
	addChild(personHead);
	personHead->setPosition(Vec2(FRAMESIZE.width/6, this->getContentSize().height*2/3));
	
	__Dictionary * message = __Dictionary::createWithContentsOfFile("chinesexml/personName.xml");
	auto strName = message->valueForKey(PersonName_own[0])->getCString();//0是哥哥1是弟弟
	name = Label::createWithTTF(strName, "fnt/JDJHCU.TTF", 50);
	addChild(name);

	message = __Dictionary::createWithContentsOfFile("chinesexml/personmotto.xml");
	auto strMotto = message->valueForKey(PersonName_own[0])->getCString();//0是哥哥1是弟弟
	text = Label::createWithTTF(strMotto, "fnt/JDJHCU.TTF", 32);
	addChild(text);

	name->setAnchorPoint(Vec2(0, 0.5));
	text->setAnchorPoint(Vec2(0, 0.5));
	name->setPosition(Vec2(FRAMESIZE.width / 3, this->getContentSize().height * 3 / 4));
	text->setPosition(Vec2(FRAMESIZE.width / 3, this->getContentSize().height * 3 / 4 - name->getContentSize().height));
	return true;
}

Rect PageAPersonModule::getHeadPicBoundingBox()
{
	return personHead->getBoundingBox();
}

Rect PageAPersonModule::getNameBoundingBox()
{
	return name->getBoundingBox();
}

Rect PageAPersonModule::getTextBoundingBox()
{
	return text->getBoundingBox();
}

void PageAPersonModule::changeName(std::string str)
{
	name->setString(str);
}

void PageAPersonModule::changeText(std::string str)
{
	text->setString(str);
}