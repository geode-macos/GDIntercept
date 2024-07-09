#pragma once

#include "ButtonBar.hpp"
#include "../include.hpp"
#include "lists/JSONCodeBlock.hpp"
#include "../objects/ThemeStyle.hpp"

class CodeBlock : public JSONCodeBlock {
public:
    static size_t buttonCount;

    static CodeBlock* create(const CCSize& size, const CCSize& buttonBarSize);

    void updateInfo(HttpInfo* info);
private:
    static std::vector<std::pair<char, SEL_MenuHandler>> dataTypes;
    static char currentDataType;

    std::unordered_map<char, CCLabelBMFont*> m_labels;
    HttpInfo* m_info;

    bool init(const CCSize& size, const CCSize& buttonBarSize);
    void doNothing(CCObject* sender);
    void onBody(CCObject* sender);
    void onQuery(CCObject* sender);
    void onHeaders(CCObject* sender);
    void onResponse(CCObject* sender);
    void updateDataTypeColor(const char type);
};