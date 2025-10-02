#pragma once

struct Text {
    char mode;
    std::string content;
};

int get_text_start(const char **argv, int argc);
std::string get_text_content(int text_start, const char **argv, int argc);
std::string get_processed_text(Text& text, const char **args, int start, int end);
void help_page();
