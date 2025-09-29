#pragma once

struct Text {
    char mode;
    std::string content;
};

bool iterate_arguments(Text& text, const char **args, int start, int end);
void help_page();
