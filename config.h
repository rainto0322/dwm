/* See LICENSE file for copyright and license details. */

#include <X11/XF86keysym.h>

static const char *USER = "  Hi ~! Rainto ~ ʕ•̀ᴥ•́ʔ ✧";
static const char *autostartscript = "bash ~/.config/dwm/script/run.sh";
/* appearance */
/* 0 means no systray */
static int showsystray              = 1;
/* border pixel of windows */
static const unsigned int borderpx  = 4;
/* snap pixel */
static const unsigned int snap      = 32;
/* horiz inner gap between windows */
static const unsigned int gappih    = 5;
/* vert inner gap between windows */
static const unsigned int gappiv    = 5;
/* horiz outer gap between windows and screen edge */
static const unsigned int gappoh    = 5;
/* vert outer gap between windows and screen edge */
static const unsigned int gappov    = 5;
/* 1 means no outer gap when there is only one window */
static const int smartgaps          = 0;
/* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systraypinning = 1;
/* systray spacing */
static const unsigned int systrayspacing = 9;
/* 1: if pinning fails,display systray on the 1st monitor,False: display systray on last monitor*/
static const int systraypinningfailfirst = 0;
/* 0 means no bar */
static const int showbar            = 1;
static const int showtab            = showtab_auto;
/* 0 means bottom tab */
static const int toptab             = 1;
/* 1 means the bar will float(don't have padding),0 means the bar have padding */
static const int floatbar           = 1;
/* 0 means bottom bar */
static const int topbar             = 0;
static const int horizpadbar        = 5;
static const int vertpadbar         = 15;
static const int vertpadtab         = 38;
/* horizontal padding between the underline and tag */
static const unsigned int ulinepad      = 5;
/* thickness / height of the underline */
static const unsigned int ulinestroke   = 2;
/* how far above the bottom of the bar the line should appear */
static const unsigned int ulinevoffset  = 0;
/* 1 to show underline on all tags, 0 for just the active ones */
static const int ulineall               = 0;
static const int scalepreview       = 4;
/* 1 means enable, 0 is off */
static const int tag_preview        = 1;
/* 0 means use SchemeSel for selected non vacant tag */
static const int colorfultag        = 1;
/*  1 means the new window will attach on the end; 
    0 means the new window will attach on the front,default is front */
static const int new_window_attach_on_end = 0;
static const char *overviewtag = " ʕ•ᴥ•ʔ OVERVOEW";
static const Layout overviewlayout = { " ",  overview };
/* title icon size | space between icon and title */
/* layout(s) */
/* factor of master area size [0.05..0.95] */
static const float mfact     = 0.6;
/* number of clients in master area */
static const int nmaster     = 1;
/* 1 means respect size hints in tiled resizals */
static const int resizehints = 0;
/* 1 will force focus on the fullscreen window */
static const int lockfullscreen = 1;

#define ICONSIZE 19 
#define ICONSPACING 10
static const char *fonts[] = {"Serif:style:Bold:style:Italic:size=15" ,"JetBrainsMono Nerd Font Mono:style:Italic:size=25" };

// theme
#include "themes/dracula.h"
static const char *colors[][3]      = {
    /*                     fg       bg      border */
    [SchemeNorm]       = { white,   black,  gray2 },
    [SchemeSel]        = { gray4,   blue,   blue},
    [SchemeSelGlobal]  = { black,   black,  orange},
    [SchemeTitle]      = { white,   black,  black },
    [TabSel]           = { blue,    gray2,  black },
    [TabNorm]          = { gray3,   black,  black },
    [SchemeTag]        = { gray3,   black,  black },
    [SchemeTag1]       = { blue,    black,  black },
    [SchemeTag2]       = { red,     black,  black },
    [SchemeTag3]       = { orange,  black,  black },
    [SchemeTag4]       = { green,   black,  black },
    [SchemeTag5]       = { pink,    black,  black },
    [SchemeLayout]     = { green,   black,  black },
    [SchemeBtnPrev]    = { green,   black,  black },
    [SchemeBtnNext]    = { yellow,  black,  black },
    [SchemeBtnClose]   = { red,     black,  black },
};

/* tagging */
static char *tags[] = {" 󰄛 "," 󰈺 "," 󰈺 "," 󰈺 "};
static const int tagschemes[] = {
    SchemeTag1, SchemeTag2, SchemeTag3, SchemeTag4, SchemeTag5
};

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[Tile]",      tile },
    { "[Mono]",      monocle },
};

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,              KEY, view,       {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,    KEY, tag,        {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,  KEY, toggleview, {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* commands */
static const Key keys[] = {
    /* modifier                         key         function        argument */
// xrandr --output HDMI-1 --brightness 1

    // // brightness and audio 
    // {0,                       XF86XK_AudioLowerVolume, spawn, {.v = downvol}},
	// {0,                       XF86XK_AudioMute, spawn, {.v = mutevol }},
	// {0,                       XF86XK_AudioRaiseVolume, spawn, {.v = upvol}},
	// {0,				XF86XK_MonBrightnessUp,		spawn,	{.v = light_up}},
	// {0,				XF86XK_MonBrightnessDown,	spawn,	{.v = light_down}},
    // // screenshot fullscreen and cropped
    // {MODKEY|ControlMask,                XK_u,       spawn,
    //     SHCMD("maim | xclip -selection clipboard -t image/png")},
    // {MODKEY,                            XK_u,       spawn,
    //     SHCMD("maim --select | xclip -selection clipboard -t image/png")},



    // shift view
    { MODKEY,                           XK_Left,    shiftview,      {.i = -1 } },
    { MODKEY,                           XK_Right,   shiftview,      {.i = +1 } },

    { MODKEY,                           XK_j,       focusstack,     {.i = +1 } },
    { MODKEY,                           XK_k,       focusstack,     {.i = -1 } },
    { MODKEY|ShiftMask,                 XK_j,       movestack,      {.i = +1 } },
    { MODKEY|ShiftMask,                 XK_k,       movestack,      {.i = -1 } },
    { MODKEY|ShiftMask,                 XK_Return,  zoom,           {0} },
    { MODKEY,                           XK_Tab,     view,           {0} },

    // // change m,cfact sizes 
    { MODKEY|ControlMask,                 XK_j,       setmfact,       {.f = -0.05} },
    { MODKEY|ControlMask,                 XK_k,       setmfact,       {.f = +0.05} },
    { MODKEY|ControlMask,                 XK_h,       setcfact,       {.f = +0.25} },
    { MODKEY|ControlMask,                 XK_l,       setcfact,       {.f = -0.25} },

    { MODKEY,                           XK_space,   setlayout,      {0} },
    { MODKEY,                           XK_comma,   focusmon,       {.i = -1 } },
    { MODKEY,                           XK_period,  focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,                 XK_comma,   tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,                 XK_period,  tagmon,         {.i = +1 } },
    // 主窗口 +-
    { MODKEY,                           XK_i,       incnmaster,     {.i = +1 } },
    { MODKEY,                           XK_d,       incnmaster,     {.i = -1 } },
    // shift view
    { MODKEY,                           XK_h,       viewtoleft,      {.i = -1 } },
    { MODKEY,                           XK_l,       viewtoright,     {.i = +1 } },
    // set float fullscreen global
    { MODKEY,                           XK_v,       togglefloating, {0} },
    { MODKEY,                           XK_f,       togglefullscr,  {0} },
    { MODKEY,                           XK_g,       toggleglobal,   {0} },
    { MODKEY|ShiftMask,                 XK_b,       toggleborder,   {0} },
    { MODKEY,                           XK_a,       toggleoverview, {0} },
    // toggle stuff
    { MODKEY,                           XK_b,       togglebar,      {0} },
    { MODKEY            ,               XK_t,       toggletab,      { -1 } },
    { MODKEY            ,               XK_F12,     togglesystray,  {0} },
    // kill window
    { MODKEY,                           XK_q,       killclient,     {0} },
    // hide & restore windows
    { MODKEY,                           XK_e,       hidewin,        {0} },
    { MODKEY|ShiftMask,                 XK_e,       restorewin,     {0} },
    // 退出dwm
    { MODKEY,              XK_BackSpace,    quit,            {1} },
    { MODKEY|ShiftMask,    XK_BackSpace,    quit,            {0} },

    { MODKEY,   XK_Return,  spawn,  SHCMD("st")},
    { MODKEY,   XK_c,       spawn,  SHCMD("firefox") },
    { MODKEY,   XK_e,       spawn,  SHCMD("thunar") },
    { MODKEY,   XK_p,       spawn,  SHCMD("rofi -show drun") },

    { 0,    XF86XK_AudioLowerVolume,    spawn,  SHCMD("notify-send -r 9527 -h int:value:$(amixer set Master 5%- | tail -n1 | sed -r \"s/.*\\[(.*)%\\].*/\\1/\") -h string:hlcolor:#689d6a \"Volume\"") },
    { 0,    XF86XK_AudioRaiseVolume,    spawn,  SHCMD("notify-send -r 9527 -h int:value:$(amixer set Master 5%+ | tail -n1 | sed -r \"s/.*\\[(.*)%\\].*/\\1/\") -h string:hlcolor:#689d6a \"Volume\"") },
    { 0,    XF86XK_AudioMute,           spawn,  SHCMD("notify-send -r 9527 -h int:value:$(amixer set Master toggle | tail -n1 | sed -r \"s/.*\\[(.*)%\\].*/\\1/\") -h string:hlcolor:#689d6a \"Volume\"") },
    TAGKEYS(XK_y, 0)
    TAGKEYS(XK_u, 1)
    TAGKEYS(XK_i, 2)
    TAGKEYS(XK_o, 3)
};


static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating  isglobal   monitor */
    { "code",     NULL,       NULL,       1 << 0,       0,          0,         0 },

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        cyclelayout,    {.i = +1 } },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button2,        spawn,          SHCMD("st") },

    /* Keep movemouse? */
    /* { ClkClientWin, MODKEY,       Button1,    movemouse,      {0} }, */
    { ClkClientWin,    MODKEY,       Button1,    moveorplace,    {.i = 0} },
    { ClkClientWin,    MODKEY,       Button2,    togglefloating, {0} },
    { ClkClientWin,    MODKEY,       Button3,    resizemouse,    {0} },
    { ClkClientWin,    ControlMask,  Button3,    dragcfact,      {0} },
    { ClkTagBar,       0,            Button1,    view,           {0} },
    { ClkTagBar,       0,            Button3,    toggleview,     {0} },
    { ClkTagBar,       MODKEY,       Button1,    tag,            {0} },
    { ClkTagBar,       MODKEY,       Button3,    toggletag,      {0} },
    { ClkTagBar,       0,            Button4,    viewtoleft,     {0} },
    { ClkTagBar,       0,            Button5,    viewtoright,    {0} },
    { ClkTabBar,       0,            Button1,    focuswin,       {0} },
    { ClkTabBar,       0,            Button1,    focuswin,       {0} },
    { ClkTabPrev,      0,            Button1,    movestack,      { .i = -1 } },
    { ClkTabNext,      0,            Button1,    movestack,      { .i = +1 } },
    { ClkTabClose,     0,            Button1,    killclient,     {0} },
};
