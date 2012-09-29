// generated by Fast Light User Interface Designer (fluid) version 1.0110

#include "Activator.h"

void Activator::cb_fKeyCondition_i(Fl_Check_Button*, void*) {
  if (fKeyCondition->value()) {
    fCondOwnerKeyId->activate();
    fCondKeyId->activate();
    fCondKeyDescr->activate();
} else {
    fCondOwnerKeyId->deactivate();
    fCondKeyId->deactivate();
    fCondKeyDescr->deactivate();
};
}
void Activator::cb_fKeyCondition(Fl_Check_Button* o, void* v) {
  ((Activator*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_fKeyCondition_i(o,v);
}

void Activator::cb_fSpawn_i(Fl_Check_Button*, void*) {
  if (fSpawn->value()) {
    fMonsterLevel->activate();
} else {
    fMonsterLevel->deactivate();
};
}
void Activator::cb_fSpawn(Fl_Check_Button* o, void* v) {
  ((Activator*)(o->parent()->parent()->parent()->user_data()))->cb_fSpawn_i(o,v);
}

void Activator::cb_Test_i(Fl_Button*, void*) {
  int n = fSoundeffect->value();
if (n != -1)  {
	gSoundControl.RequestTrigSound(gSoundControl.fTrigSoundList[n].id);
};
}
void Activator::cb_Test(Fl_Button* o, void* v) {
  ((Activator*)(o->parent()->parent()->parent()->user_data()))->cb_Test_i(o,v);
}

void Activator::cb_fAddKey_i(Fl_Check_Button*, void*) {
  if (fAddKey->value()) {
    fKeyDescr->activate();
    fKeyId->activate();
    fKeyPicture->activate();
} else {
    fKeyDescr->deactivate();
    fKeyId->deactivate();
    fKeyPicture->deactivate();
};
}
void Activator::cb_fAddKey(Fl_Check_Button* o, void* v) {
  ((Activator*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_fAddKey_i(o,v);
}

void Activator::cb_fBroadcast_i(Fl_Check_Button*, void*) {
  if (fBroadcast->value()) {
    fBlocks->activate();
} else {
    fBlocks->deactivate();
};
}
void Activator::cb_fBroadcast(Fl_Check_Button* o, void* v) {
  ((Activator*)(o->parent()->parent()->parent()->user_data()))->cb_fBroadcast_i(o,v);
}

void Activator::cb_Ok_i(Fl_Return_Button*, void*) {
  fOk = true;
fWindow->hide();
}
void Activator::cb_Ok(Fl_Return_Button* o, void* v) {
  ((Activator*)(o->parent()->user_data()))->cb_Ok_i(o,v);
}

Activator::Activator(Fl_Text_Buffer *buf) {
  { fWindow = new Fl_Window(500, 395, "Configure activator");
    fWindow->user_data((void*)(this));
    { Fl_Tabs* o = new Fl_Tabs(15, 4, 470, 334);
      o->align(FL_ALIGN_CENTER);
      { Fl_Group* o = new Fl_Group(15, 4, 470, 312, "Conditions");
        o->tooltip("Set conditions when the activator block is enabled.");
        o->hide();
        { Fl_Group* o = new Fl_Group(25, 14, 450, 91);
          o->box(FL_DOWN_FRAME);
          { fKeyCondition = new Fl_Check_Button(150, 28, 28, 15, "Conditional key:");
            fKeyCondition->tooltip("The text activator depend conditional on a key. The test only applies to one \
player .");
            fKeyCondition->down_box(FL_DOWN_BOX);
            fKeyCondition->callback((Fl_Callback*)cb_fKeyCondition);
            fKeyCondition->align(FL_ALIGN_LEFT);
            fKeyCondition->when(FL_WHEN_CHANGED);
          } // Fl_Check_Button* fKeyCondition
          { fCondKeyId = new Fl_Input(345, 23, 55, 25, "Key:");
            fCondKeyId->tooltip("The unique number of the key");
            fCondKeyId->deactivate();
          } // Fl_Input* fCondKeyId
          { fCondOwnerKeyId = new Fl_Input(345, 62, 55, 25, "Owner:");
            fCondOwnerKeyId->tooltip("The ID of the owner that created the key. Leaving it empty will use the curre\
nt chunk owner.");
            fCondOwnerKeyId->deactivate();
          } // Fl_Input* fCondOwnerKeyId
          { fCondKeyDescr = new Fl_Input(155, 62, 87, 25, "Message:");
            fCondKeyDescr->tooltip("A message used if condition fails.");
            fCondKeyDescr->deactivate();
          } // Fl_Input* fCondKeyDescr
          o->end();
        } // Fl_Group* o
        { fInhibit = new Fl_Input(221, 170, 95, 25, "Inhibit retrigger:");
          fInhibit->tooltip("Minimum number of seconds until the next activation. The default will increas\
e when giving awards.");
        } // Fl_Input* fInhibit
        { fMinLevel = new Fl_Input(221, 210, 95, 25, "Minimum player level:");
          fMinLevel->tooltip("The player must be at least this level. It is only tested for the player that\
 triggered the trap.");
        } // Fl_Input* fMinLevel
        { fMaxLevel = new Fl_Input(221, 250, 95, 25, "Maximum player level:");
          fMaxLevel->tooltip("The player must be at most this level. It is only tested for the player that \
triggered the trap.");
        } // Fl_Input* fMaxLevel
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(15, 8, 470, 306, "Actions");
        o->tooltip("Actions that will happen when the activator block is triggered.");
        { fSpawn = new Fl_Check_Button(145, 8, 30, 20, "Spawn monster:");
          fSpawn->tooltip("Spawn a monster, attacking the user immediately.");
          fSpawn->down_box(FL_DOWN_BOX);
          fSpawn->callback((Fl_Callback*)cb_fSpawn);
          fSpawn->align(FL_ALIGN_LEFT);
        } // Fl_Check_Button* fSpawn
        { fMonsterLevel = new Fl_Choice(216, 8, 55, 25, "level modifier");
          fMonsterLevel->tooltip("The relative level of the monster compared to the default monster level.");
          fMonsterLevel->down_box(FL_BORDER_BOX);
          fMonsterLevel->align(FL_ALIGN_RIGHT);
          fMonsterLevel->deactivate();
          fMonsterLevel->add("-2|-1|0|+1|+2");
        } // Fl_Choice* fMonsterLevel
        { fSoundeffect = new Fl_Choice(145, 41, 95, 22, "Sound effect:");
          fSoundeffect->tooltip("A sound effect played");
          fSoundeffect->down_box(FL_BORDER_BOX);
        } // Fl_Choice* fSoundeffect
        { Fl_Button* o = new Fl_Button(262, 41, 70, 20, "Test");
          o->tooltip("Listen to the sound effect now");
          o->callback((Fl_Callback*)cb_Test);
        } // Fl_Button* o
        { fObject = new Fl_Choice(145, 77, 95, 22, "Add reward:");
          fObject->tooltip("Give a reward to the player");
          fObject->down_box(FL_BORDER_BOX);
        } // Fl_Choice* fObject
        { fJellyBlock = new Fl_Choice(145, 113, 95, 22, "Jelly block:");
          fJellyBlock->tooltip("Turn block in specified direction transparent for 15s.");
          fJellyBlock->down_box(FL_BORDER_BOX);
        } // Fl_Choice* fJellyBlock
        { Fl_Group* o = new Fl_Group(15, 188, 470, 46);
          o->box(FL_DOWN_FRAME);
          { fAddKey = new Fl_Check_Button(88, 203, 28, 15, "Add key:");
            fAddKey->tooltip("Give a key to the player.");
            fAddKey->down_box(FL_DOWN_BOX);
            fAddKey->callback((Fl_Callback*)cb_fAddKey);
            fAddKey->align(FL_ALIGN_LEFT);
            fAddKey->when(FL_WHEN_CHANGED);
          } // Fl_Check_Button* fAddKey
          { fKeyDescr = new Fl_Input(168, 198, 87, 25, "Descr:");
            fKeyDescr->tooltip("The description of the key.");
            fKeyDescr->deactivate();
          } // Fl_Input* fKeyDescr
          { fKeyId = new Fl_Input(279, 198, 55, 25, "Id:");
            fKeyId->tooltip("The unique ID of the key, used by conditions in other activators.");
            fKeyId->deactivate();
          } // Fl_Input* fKeyId
          { fKeyPicture = new Fl_Choice(343, 198, 55, 25, "Key picture");
            fKeyPicture->tooltip("Choose how the key shall look, from a list of pre defined pictures.");
            fKeyPicture->down_box(FL_BORDER_BOX);
            fKeyPicture->align(FL_ALIGN_RIGHT);
            fKeyPicture->deactivate();
            fKeyPicture->add("Key");
          } // Fl_Choice* fKeyPicture
          o->end();
        } // Fl_Group* o
        { Fl_Text_Editor* o = new Fl_Text_Editor(20, 258, 460, 49, "Text message:");
          o->tooltip("One or more lines of text that will be shown.");
          o->buffer(buf);
        } // Fl_Text_Editor* o
        { fBroadcast = new Fl_Check_Button(144, 149, 28, 15, "Broadcast:");
          fBroadcast->tooltip("Everything activated will happen for all players inside a limited distance. A\
ll actions below are affected.");
          fBroadcast->down_box(FL_DOWN_BOX);
          fBroadcast->callback((Fl_Callback*)cb_fBroadcast);
          fBroadcast->align(FL_ALIGN_LEFT);
          fBroadcast->when(FL_WHEN_CHANGED);
        } // Fl_Check_Button* fBroadcast
        { fBlocks = new Fl_Input(172, 144, 55, 25, "blocks");
          fBlocks->tooltip("The distance measured in blocks to players that will receive the broadcast");
          fBlocks->align(FL_ALIGN_RIGHT);
          fBlocks->deactivate();
        } // Fl_Input* fBlocks
        o->end();
      } // Fl_Group* o
      o->end();
    } // Fl_Tabs* o
    { Fl_Return_Button* o = new Fl_Return_Button(45, 354, 95, 20, "Ok");
      o->tooltip("There is no way to cancel creation of an activator. But it can be removed aft\
erwards.");
      o->callback((Fl_Callback*)cb_Ok);
    } // Fl_Return_Button* o
    fWindow->end();
  } // Fl_Window* fWindow
  fWindow->show();
}