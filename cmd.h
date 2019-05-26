#ifndef CMD_H
#define CMD_H
#include <iostream>
#include "info.h"
#include "builder.h"

using InfoResults = std::ostream& (std::ostream&, Info&, bool);

std::ostream& func (std::ostream& fstr, Info& i, bool command);

bool do_command (Builder& build,Info& i, const char* fname, InfoResults f,bool command);

bool isCommand (const char* com);

void outUndef (const char* fname);

void outOk(bool ok);

void outIgnored (char* mes);

bool input (Builder& build, Info& data, const char* filename);

void cmd (Builder& build,Info& data,InfoResults f,int num, char* arg []);
#endif // CMD_H
