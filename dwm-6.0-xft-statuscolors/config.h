/* 
Configuration file for DWM. 
Maintainer: illusionist
https://www.github.com/nixmeal
*/
/*Appearance*/
#define NUMCOLORS 5
static const char colors[NUMCOLORS][ColLast][9] = {
    // border     fg         bg
    { "#ababab", "#7d7d7d", "#020202" },  // 01 - normal
    { "#FFA500", "#FFA500", "#020202" },  // 14 - orange
    { "#B3354C", "#B3354C", "#020202" },  // 03 - urgent
    { "#1c678c", "#1c678c", "#020202" },  // 02 - selected
    { "#1c678c", "#1c678c", "#020202" },  // 0F - White
//    { "#00FF00", "#20b2e7", "#00FF00" },  // 04 - black
//    { "#20b2e7", "#20b2e7", "#020202" },  // 0F - White


//    { "#FF0000", "#FF0000", "#020202" },  // 05 - red
//    { "#608040", "#608040", "#020202" },  // 06 - green
//    { "#877C43", "#877C43", "#020202" },  // 07 - yellow
//    { "#1C678C", "#1C678C", "#020202" },  // 08 - blue
//    { "#000000", "#000000", "#000000" },  // unusable
//    { "#337373", "#337373", "#020202" },  // 0B - cyan
//    { "#E300FF", "#E300FF", "#020202" },  // 09 - magenta
//    { "#808080", "#808080", "#020202" },  // 0C - light gray
//    { "#4C4C4C", "#4C4C4C", "#020202" },  // 0D - gray
//    { "#FFEE00", "#FFEE00", "#020202" },  // 0E - yellow2
///*    { "#B1D354", "#B1D354", "#020202" },  // 0F - light green */
//    { "#20b2e7", "#20b2e7", "#020202" },  // 0F - White
//    { "#BF9F5F", "#BF9F5F", "#020202" },  // 10 - light yellow
//    { "#3995BF", "#3995BF", "#020202" },  // 11 - light blue
//    { "#A64286", "#A64286", "#020202" },  // 12 - light magenta
//    { "#6C98A6", "#6C98A6", "#020202" },  // 13 - light cyan
//    { "#FFA500", "#FFA500", "#020202" },  // 14 - orange
//
//    { "#0300ff", "#0300ff", "#802635" },  // 15 - warning
//
//
//
//    { "#ababab", "#7d7d7d", "#020202" },  // 01 - normal
//    { "#20b2e7", "#20b2e7", "#020202" },  // 02 - selected
//    { "#B3354C", "#B3354C", "#020202" },  // 03 - urgent
//    { "#FFA500", "#FFA500", "#020202" },  // 14 - orange
//    { "#20b2e7", "#20b2e7", "#020202" },  // 0F - White

};

static const char font[]		= "ohsnap.icons";
//static const char font[]		= "-misc-ohsnap.icons-medium-r-normal--0-0-75-75-c-0-iso8859-1";
static const unsigned int borderpx  	    = 2;        // border pixel of windows
static const unsigned int snap              = 2;     	// snap pixel
static const unsigned int gappx		        = 4;
static const Bool showbar                   = True;  	// False means no bar
static const Bool topbar                    = True;  	// False means bottom bar
static const unsigned int systrayspacing    = 4;        // systray spacing 
static const Bool showsystray               = True;     // False means no systray

/* Layout(s) */
static const float mfact      = 0.63;  // factor of master area size [0.05..0.95]
static const int nmaster      = 1;     // number of clients in master area
static const Bool resizehints = False; // True means respect size hints in tiled resizals
static const Layout layouts[] = {
	/* symbol	arrange function */
	{ "[ÿ]",	False,	monocle },    /* first entry is default */
	{ "[ý]",	False,	NULL },       /* no layout function means floating behavior */
	{ "[þ]",	True,	tile },
	{ "[ü]",	True,	bstack },
	{ "[ú]",	True,	chat },
};

/* Tagging */
//static const char *tags[] = { "A", "B", "C", "D", "E" };
static const Tag tags[] = {
    /* name     layout          mfact   nmaster*/
    { "term",   &layouts[2],    -1,     -1 },
    { "web",    &layouts[2],    0.80,   -1 },
    { "code",   &layouts[0],    -1,     -1 },
    { "ssh",    &layouts[3],    -1,     -1 },
    { "virt",   &layouts[0],    -1,     -1 },
    { "misc",   &layouts[2],    -1,     -1 },
};

static const Rule rules[] = {
	/* class      		instance	title		tags mask	isfloating 	monitor */
	{ "Gimp",     		NULL,       NULL,       	1 << 4,     True,      	-1 },
	{ "Firefox",		NULL,		NULL,	    	1 << 0,	  	False,		-1 },
};

#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },


/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenurun[] 		= 	{ "dmenu_run", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
static const char *terminal[]  		= 	{ "urxvtc", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenurun } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = terminal } },
	//{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_b,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_c,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = terminal } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
