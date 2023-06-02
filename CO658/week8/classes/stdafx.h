#pragma once

enum TStates { On, Off, Broken};

class Bulb;

typedef void (Bulb::*CBP)();
typedef bool (Bulb::*GP)();
