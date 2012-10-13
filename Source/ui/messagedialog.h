// Copyright 2012 The Ephenation Authors
//
// This file is part of Ephenation.
//
// Ephenation is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 3.
//
// Ephenation is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Ephenation.  If not, see <http://www.gnu.org/licenses/>.
//

#pragma once

#include <string>

// This class manages the in-game dialog messages.
#include <Rocket/Core.h>

using std::string;

class MessageDialog : public Rocket::Core::EventListener {
public:
	MessageDialog();
	~MessageDialog();

	void Init(Rocket::Core::Context *context);

	void Set(const string &title, const string &body, void (*callback)(void));

	// Draw the dialog.
	virtual void Draw();

	// Process the incoming event.
	virtual void ProcessEvent(Rocket::Core::Event& event);
private:
	Rocket::Core::Context *fRocketContext;
	Rocket::Core::ElementDocument *fDocument;
	Rocket::Core::Element *fHeader, *fContent;
	void (*fCallback)(void);
};