#ifndef TYPES_H
#define TYPES_H

/// basic defined type
typedef unsigned char u8_t;
typedef unsigned short u16_t;
typedef unsigned int u32_t;
typedef signed char s8_t;
typedef signed short s16_t;
typedef signed int s32_t;

/// exception procession type
enum exception_t {

};

/// debug flag type
typedef enum {
    OpenDebug   = 0,
    CloseDebug  = 1
}debug_t;

/// WARNING: After you change the on-off of DebugModE, you should
/// clear your project and build again OR rebuild your project
/// directly. IF you use RUN button in qtcreator, there is no change
/// with debug. I consider that this is a bug with moc.

/// DebugModE(controled by DEBUG) only control the show or hide of
/// debugButton in every working window, and it not control the show
/// or hide of debug window.
/// Another const argument: ShowDebugWindoW(controled by BOOTDEBUG),
/// in windowinterface, will control the debug window.
#define DEBUG       OpenDebug      // control debugButton in normal window
#define BOOTDEBUG   CloseDebug       // control debug window in boot

const debug_t DebugModE = DEBUG;


typedef enum {
    BottomFlag,
    StandbyFlag,
    DebugFlag
}WindowFlag;

#endif // TYPES_H
