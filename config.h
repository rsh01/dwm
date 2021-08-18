/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int gappx     = 15;        /* gaps between windows */
static const unsigned int snap      = 0;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = {
        "Fira Code Retina:size=12:antialias=true:autohint=true",
        /* "Product Sans:size=13:antialias=true:autohint=true", */
        "Stick:size=12",
        "Material Design Icons:size=12",
        "JoyPixels:pixelsize=10:antialias=true:autohint=true",
        "FontAwesome:size=10",
};

static const char dmenufont[]       = "monospace:size=10";

/* Gruvbox */
/* static const char col_gray1[]       = "#1D1D1B"; */
/* static const char col_gray2[]       = "#444444"; */
/* static const char col_gray3[]       = "#ffffff"; */
/* static const char col_border[]      = "#83A598"; */
/* static const char col_gray4[]       = "#000000"; */
/* static const char col_cyan[]        = "#83A598"; */

/* Gruvbox Light */
/* static const char col_gray1[]       = "#EADAB1"; */
/* static const char col_gray2[]       = "#444444"; */
/* static const char col_gray3[]       = "#000000"; */
/* static const char col_border[]      = "#FA4833"; */
/* static const char col_gray4[]       = "#000000"; */
/* static const char col_cyan[]        = "#F2E5BC"; */

/* Monochrome */
static const char col_gray1[]       = "#171A1F";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#ffffff";
static const char col_border[]      = "#ffffff";
static const char col_gray4[]       = "#ffffff";
static const char col_cyan[]        = "#303337";

/* Nord */
/* static const char col_gray1[]       = "#3B4252"; */
/* static const char col_gray2[]       = "#444444"; */
/* static const char col_gray3[]       = "#ffffff"; */
/* static const char col_border[]      = "#EBCB8B"; */
/* static const char col_gray4[]       = "#000000"; */
/* static const char col_cyan[]        = "#81A1C1"; */

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_border },
};

/* tagging */
static const char *tags[] = { "α", "β", "γ", "δ", "ε", "ζ", "η", "θ", "ι" };
/* static const char *tags[] = { "Γ", "Δ", "Θ", "Λ", "Ξ", "Π", "Σ", "Φ", "Ψ" }; */
/* static const char *tags[] = { "一", "二", "三", "四", "五", "六", "七", "八", "九" }; */
/* static const char *tags[] = { "", "", "", "", "" }; */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title         tags mask     iscentered     isfloating   monitor */
	{ "Sxiv",     "sxiv",     "sxiv",       0,            1,             1,           -1 },
	{ "Gcolor2",  "gcolor2",  "gcolor2",    0,            1,             1,           -1 },
	{ "Alacritty","Alacritty","alsamixer",  0,            1,             1,           -1 },
	{ "Alacritty","Alacritty","vit",        0,            1,             1,           -1 },
	{ "Alacritty","Alacritty","python",     0,            1,             1,           -1 },
	{ "Alacritty","Alacritty","ncmpcpp",    0,            1,             1,           -1 },
	{ "Alacritty","Alacritty","calcurse",   0,            1,             1,           -1 },
	{ "Alacritty","Alacritty","vimwiki_d",  0,            1,             1,           -1 },
	{ "Display",  "display",  NULL,         0,            1,             1,           -1 },
	{ "Pcmanfm",  "pcmanfm",  NULL,         0,            1,             1,           -1 },
	{ "mpv",      NULL,       NULL,         0,            0,             1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *termcmd[]  = { "st", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_o,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Tab,    zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_Tab,    quit,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
 	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_Insert, view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_Insert, tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
        { ClkStatusText,        ShiftMask,      Button3,        spawn,          SHCMD("st -e nvim ~/repos/dwmblocks/config.h") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
