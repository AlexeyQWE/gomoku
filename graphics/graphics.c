#include <stdio.h>
#include <stdlib.h>
#include "gtk/gtk.h"
#include <string.h>
#include <ctype.h>

#include "global.h"

#define TABLE_Y 18

gint delete_event( GtkWidget *widget,
                           GdkEvent  *event,
                           gpointer   data )
{
    gtk_main_quit ();
    return FALSE;
}

void dialogButOk_click(GtkButton *b)
{
    gtk_widget_destroy (b);
}

typedef enum _ButtonCode
{
    BUTTON_0,
    BUTTON_1,  
} ButtonCode;

ButtonCode codes[1] = {
	0,       
};

void on_button_activate(GtkWidget* button, gpointer *data)
{
    int choice = *(int*)data;
    if(choice == 0){
	gtk_button_set_label ((GtkButton*)button, "X");
	choice = 1;
    }else{
	gtk_button_set_label ((GtkButton*)button, "O");
	choice = 0;
    }
    *(int*)data = choice;
}

void click(GtkButton *b){
    gtk_button_get_label(b);
    return 0;
}

void callbackGame( GtkWidget *widget,
               gpointer   data )
{
    GtkWidget *Game;
    GtkWidget *hbox1, *hbox2, *hbox3, *hbox4, *hbox5, *hbox6, *hbox7, *hbox8, *hbox9, *hbox10, *hbox11, *hbox12, *hbox13, *hbox14, *hbox15;
    GtkWidget *vbox;
    GtkWidget *button;
    GtkWidget *label;
    GtkWidget *hboxMain;
    GtkWidget *vbox1;
    GtkWidget *entry;
    GtkWidget *check;
    GtkWidget *hbox;
    GtkWidget *separator;
    GtkWidget *quitbox;
    gint tmp_pos;
    gint choice = 0;
    int i, j;
    
    Game = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(Game), 500, 500);
    gtk_window_set_title (GTK_WINDOW (Game), "GOMOKU");
        g_signal_connect (G_OBJECT (Game), "delete_event",
                             G_CALLBACK (dialogButOk_click), NULL);
    gtk_container_set_border_width (GTK_CONTAINER (Game), 10);
    hboxMain = gtk_hbox_new(0, 0);
    vbox = gtk_vbox_new(0, 0);
    gtk_container_add (GTK_CONTAINER (hboxMain), vbox);
    gtk_widget_show (vbox);

    label = gtk_label_new ("GOMOKU");
    gtk_misc_set_alignment (GTK_MISC (label), 0, 0);
    gtk_box_pack_start (GTK_BOX (vbox), label, TRUE, TRUE, 0);
    gtk_widget_show (label);
    hbox1 = gtk_hbox_new(FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (hbox1), 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox1, TRUE, TRUE, 0);
    hbox2 = gtk_hbox_new(FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (hbox2), 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox2, TRUE, TRUE, 0);
    hbox3 = gtk_hbox_new(FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (hbox3), 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox3, 0, 0, 0);
    hbox4 = gtk_hbox_new(FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (hbox4), 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox4, 0, 0, 0);
    hbox5 = gtk_hbox_new(FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (hbox5), 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox5, 0, 0, 0);
    hbox6 = gtk_hbox_new(FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (hbox6), 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox6, 0, 0, 0);
    hbox7 = gtk_hbox_new(FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (hbox7), 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox7, 0, 0, 0);
    hbox8 = gtk_hbox_new(FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (hbox8), 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox8, 0, 0, 0);
    hbox9 = gtk_hbox_new(FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (hbox9), 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox9, 0, 0, 0);
    hbox10 = gtk_hbox_new(FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (hbox10), 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox10, 0, 0, 0);
    hbox11 = gtk_hbox_new(FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (hbox11), 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox11, 0, 0, 0);
    hbox12 = gtk_hbox_new(FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (hbox12), 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox12, 0, 0, 0);
    hbox13 = gtk_hbox_new(FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (hbox13), 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox13, 0, 0, 0);
    hbox14 = gtk_hbox_new(FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (hbox14), 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox14, 0, 0, 0);
    hbox15 = gtk_hbox_new(FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (hbox15), 0);
    gtk_box_pack_start (GTK_BOX (vbox), hbox15, 0, 0, 0);
    for(j = 1; j <= 15; j++){
	for(i = 1 ; i <= 15 ; i++){
	    button = gtk_button_new_with_label ("    ");
	    gtk_widget_set_size_request(button, 27, 27);
	    g_signal_connect(G_OBJECT(button), "pressed",
                G_CALLBACK(&on_button_activate), &codes[0]);
	    switch(j){
		case 1:
		    gtk_container_add (GTK_CONTAINER (hbox1), button);
		    break;
		case 2:
		    gtk_container_add (GTK_CONTAINER (hbox2), button);
		    break;
		case 3:
		    gtk_container_add (GTK_CONTAINER (hbox3), button);
		    break;
		case 4:
		    gtk_container_add (GTK_CONTAINER (hbox4), button);
		    break;
		case 5:
		    gtk_container_add (GTK_CONTAINER (hbox5), button);
		    break;
		case 6:
		    gtk_container_add (GTK_CONTAINER (hbox6), button);
		    break;
		case 7:
		    gtk_container_add (GTK_CONTAINER (hbox7), button);
		    break;
		case 8:
		    gtk_container_add (GTK_CONTAINER (hbox8), button);
		    break;
		case 9:
		    gtk_container_add (GTK_CONTAINER (hbox9), button);
		    break;
		case 10:
		    gtk_container_add (GTK_CONTAINER (hbox10), button);
		    break;
		case 11:
		    gtk_container_add (GTK_CONTAINER (hbox11), button);
		    break;
		case 12:
		    gtk_container_add (GTK_CONTAINER (hbox12), button);
		    break;
		case 13:
		    gtk_container_add (GTK_CONTAINER (hbox13), button);
		    break;
		case 14:
		    gtk_container_add (GTK_CONTAINER (hbox14), button);
		    break;
		case 15:
		    gtk_container_add (GTK_CONTAINER (hbox15), button);
		    break;
	    }
	}
    }
    separator = gtk_hseparator_new ();
    gtk_container_add (GTK_CONTAINER (vbox), separator);
    quitbox = gtk_hbox_new (FALSE, 0);
    button = gtk_button_new_with_label ("Выход");
    g_signal_connect_swapped (G_OBJECT (button), "clicked",
                              G_CALLBACK (dialogButOk_click),
                              G_OBJECT (Game));
    gtk_box_pack_start (GTK_BOX (quitbox), button, TRUE, FALSE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), quitbox, FALSE, FALSE, 0);
    gtk_container_add (GTK_CONTAINER (Game), hboxMain);
    gtk_widget_show_all (Game);
    
    return 0;
}

void callbackSettings( GtkWidget *widget,
               gpointer   data)
{
    GtkWidget *Settings = NULL;
    GtkWidget *box1;
    GtkWidget *box2, *label2;
    GtkWidget *box3, *label3;
    GtkWidget *box4, *label4;
    GtkWidget *vbox;
    GtkWidget *button;
    GtkWidget *separator;
    GSList *group;
    Settings = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(Settings), 300, 230);
    g_signal_connect (G_OBJECT (Settings), "delete_event",
                      G_CALLBACK (dialogButOk_click),
                      NULL);
    gtk_window_set_title (GTK_WINDOW (Settings), "Настройки");
    gtk_container_set_border_width (GTK_CONTAINER (Settings), 0);
    box1 = gtk_vbox_new (FALSE, 0);
    gtk_container_add (GTK_CONTAINER (Settings), box1);
    gtk_widget_show (box1);
    /*включение выключение бота*/
    box2 = gtk_hbox_new (FALSE, 10);
    gtk_container_set_border_width (GTK_CONTAINER (box2), 10);
    gtk_box_pack_start (GTK_BOX (box1), box2, TRUE, TRUE, 0);
    gtk_widget_show (box2);
    label2 = gtk_label_new ("Бот: ");
    gtk_misc_set_alignment (GTK_MISC (label2), 0, 0);
    gtk_box_pack_start (GTK_BOX (box2), label2, TRUE, TRUE, 0);
    gtk_widget_show (label2);
    button = gtk_radio_button_new_with_label (NULL, "Выключить");
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (button), TRUE);
    gtk_box_pack_start (GTK_BOX (box2), button, TRUE, TRUE, 0);
    gtk_widget_show (button);
    group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (button));
    button = gtk_radio_button_new_with_label (group, "Включить");
    gtk_box_pack_start (GTK_BOX (box2), button, TRUE, TRUE, 0);
    gtk_widget_show (button);

    /*уровень бота*/
    box3 = gtk_hbox_new (FALSE, 10);
    gtk_container_set_border_width (GTK_CONTAINER (box3), 10);
    gtk_box_pack_start (GTK_BOX (box1), box3, TRUE, TRUE, 0);
    gtk_widget_show (box3);
        label3 = gtk_label_new ("Уровень игры бота: ");
    gtk_misc_set_alignment (GTK_MISC (label3), 0, 0);
    gtk_box_pack_start (GTK_BOX (box3), label3, TRUE, TRUE, 0);
    gtk_widget_show (label3);
    button = gtk_radio_button_new_with_label (NULL, "Новичок");
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (button), TRUE);
    gtk_box_pack_start (GTK_BOX (box3), button, TRUE, TRUE, 0);
    gtk_widget_show (button);
    group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (button));
    button = gtk_radio_button_new_with_label (group, "Защитник");
    gtk_box_pack_start (GTK_BOX (box3), button, TRUE, TRUE, 0);
    gtk_widget_show (button);
    button = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (button),
                                                          "Игрок");
    gtk_box_pack_start (GTK_BOX (box3), button, TRUE, TRUE, 0);
    gtk_widget_show (button);


    /*за кого играть*/
        box4 = gtk_hbox_new (FALSE, 10);
    gtk_container_set_border_width (GTK_CONTAINER (box4), 10);
    gtk_box_pack_start (GTK_BOX (box1), box4, TRUE, TRUE, 0);
    gtk_widget_show (box4);
        label4 = gtk_label_new ("Играющая сторона: ");
    gtk_misc_set_alignment (GTK_MISC (label4), 0, 0);
    gtk_box_pack_start (GTK_BOX (box4), label4, TRUE, TRUE, 0);
    gtk_widget_show (label4);
    button = gtk_radio_button_new_with_label (NULL, "Нолики");
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (button), TRUE);
    gtk_box_pack_start (GTK_BOX (box4), button, TRUE, TRUE, 0);
    gtk_widget_show (button);
    group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (button));
    button = gtk_radio_button_new_with_label (group, "Крестики");
    gtk_box_pack_start (GTK_BOX (box4), button, TRUE, TRUE, 0);
    gtk_widget_show (button);

    separator = gtk_hseparator_new ();
    gtk_box_pack_start (GTK_BOX (box1), separator, FALSE, TRUE, 0);
    gtk_widget_show (separator);
    box2 = gtk_vbox_new (FALSE, 10);
    gtk_container_set_border_width (GTK_CONTAINER (box2), 10);
    gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, TRUE, 0);
    gtk_widget_show (box2);
    button = gtk_button_new_with_label ("Выход");
    g_signal_connect_swapped (G_OBJECT (button), "clicked",
                              G_CALLBACK (dialogButOk_click),
                              G_OBJECT (Settings));
    gtk_box_pack_start (GTK_BOX (box2), button, TRUE, TRUE, 0);
    gtk_widget_show_all (Settings);
    return 0;
}

void callbackReeglid( GtkWidget *widget,
               gpointer   data )
{
    GtkWidget *Reeglid;
    GtkWidget *button;
    GtkWidget *vbox;
    GtkWidget *frame;
    GtkWidget *label;
    Reeglid = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(Reeglid), 300, 300);
    g_signal_connect (G_OBJECT (Reeglid), "delete_event",
                      G_CALLBACK (dialogButOk_click),
                      NULL);
    gtk_window_set_title (GTK_WINDOW (Reeglid), "Правила");
    gtk_container_set_border_width (GTK_CONTAINER (Reeglid), 10);
    vbox = gtk_vbox_new (FALSE, 5);
    frame = gtk_frame_new ("Правила игры в GOMOKU");
    label = gtk_label_new ("В гомоку играют 2 игрока,  " \
                         "в поле 9X9 или 19X19 за X и O.  "\
                         "У каждого из игроков цель " \
                         "собрать в ряд 5 крестов или нолей.");
    gtk_label_set_line_wrap (GTK_LABEL (label), TRUE);
    gtk_container_add (GTK_CONTAINER (frame), label);
    gtk_box_pack_start (GTK_BOX (vbox), frame, FALSE, FALSE, 0);
    frame = gtk_frame_new ("Фолы");
    label = gtk_label_new ("Играя за черных стоит  " \
                         "учитывать, что черная сторона  "\
                         "не может строить ряды больше пяти в ряд" \
                         "иначе настпупит проигрышь.");
    gtk_label_set_line_wrap (GTK_LABEL (label), TRUE);
    gtk_container_add (GTK_CONTAINER (frame), label);
    gtk_box_pack_start (GTK_BOX (vbox), frame, FALSE, FALSE, 0);
    button = gtk_button_new_with_label ("Выход");
    gtk_box_pack_end (GTK_BOX(vbox), button, FALSE, FALSE, 0);
        g_signal_connect_swapped (G_OBJECT (button), "clicked",
                              G_CALLBACK (dialogButOk_click),
                              G_OBJECT (Reeglid));
    gtk_container_add (GTK_CONTAINER (Reeglid), vbox);
    gtk_widget_show_all (Reeglid);
    return 0;
}

void callbackHallHero( GtkWidget *widget,
               gpointer   data )
{
    GtkWidget *HallHero;
    GtkWidget *button;
    GtkWidget *box1;
    HallHero = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(HallHero), 200, 200);
    gtk_window_set_title (GTK_WINDOW (HallHero), "GOMOKU");
    gtk_container_set_border_width (GTK_CONTAINER (HallHero), 10);   
    box1 = gtk_vbox_new (FALSE, 0);
    button = gtk_button_new_with_label (" ");
    gtk_container_add (GTK_CONTAINER (box1), button);
    button = gtk_button_new_with_label (" ");
    gtk_container_add (GTK_CONTAINER (box1), button);
    button = gtk_button_new_with_label (" ");
    gtk_container_add (GTK_CONTAINER (box1), button);
    button = gtk_button_new_with_label (" ");
    gtk_container_add (GTK_CONTAINER (box1), button);
    button = gtk_button_new_with_label (" ");
    gtk_container_add (GTK_CONTAINER (box1), button);
    gtk_container_add (GTK_CONTAINER (HallHero), box1);
    gtk_widget_show_all (HallHero);
    
    return 0;
}

void callbackExit( GtkWidget *widget,
               gpointer   data )
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box1;

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "GOMOKU");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    
    box1 = gtk_vbox_new (FALSE, 0);
    button = gtk_button_new_with_label (" ");
    gtk_container_add (GTK_CONTAINER (box1), button);

    button = gtk_button_new_with_label (" ");
    gtk_container_add (GTK_CONTAINER (box1), button);

    button = gtk_button_new_with_label (" ");
    gtk_container_add (GTK_CONTAINER (box1), button);

    button = gtk_button_new_with_label (" ");
    gtk_container_add (GTK_CONTAINER (box1), button);

    button = gtk_button_new_with_label (" ");
    gtk_container_add (GTK_CONTAINER (box1), button);



    gtk_container_add (GTK_CONTAINER (window), box1);
    
    gtk_widget_show_all (window);
    
    gtk_main ();
    return 0;
}

int main( int   argc,
          char **argv) 
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box1;
    GtkWidget *separator;
    GtkWidget *quitbox;
    
    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    gtk_window_set_title (GTK_WINDOW (window), "GOMOKU");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    
    box1 = gtk_vbox_new (FALSE, 0);
    button = gtk_button_new_with_label ("Играть");
    g_signal_connect (G_OBJECT (button), "clicked",
                      G_CALLBACK (callbackGame), (gpointer) "cool button");
     gtk_container_add (GTK_CONTAINER (box1), button);

    button = gtk_button_new_with_label ("Настройки");
    g_signal_connect (G_OBJECT (button), "clicked",
                      G_CALLBACK (callbackSettings), (gpointer) "cool button");
     gtk_container_add (GTK_CONTAINER (box1), button);

         button = gtk_button_new_with_label ("Правила");
         g_signal_connect (G_OBJECT (button), "clicked",
                      G_CALLBACK (callbackReeglid), (gpointer) "cool button");
     gtk_container_add (GTK_CONTAINER (box1), button);

         button = gtk_button_new_with_label ("Зал Славы");
         g_signal_connect (G_OBJECT (button), "clicked",
                      G_CALLBACK (callbackHallHero), (gpointer) "cool button");
     gtk_container_add (GTK_CONTAINER (box1), button);
     separator = gtk_hseparator_new ();
    gtk_container_add (GTK_CONTAINER (box1), separator);

    quitbox = gtk_hbox_new (FALSE, 0);

    button = gtk_button_new_with_label ("Выход");
    
    g_signal_connect_swapped (G_OBJECT (button), "clicked",
                              G_CALLBACK (gtk_main_quit),
                              G_OBJECT (window));
    gtk_box_pack_start (GTK_BOX (quitbox), button, TRUE, FALSE, 0);
    gtk_box_pack_start (GTK_BOX (box1), quitbox, FALSE, FALSE, 0);
    
    gtk_container_add (GTK_CONTAINER (window), box1);
    
    gtk_widget_show_all (window);
    
    gtk_main ();
    return 0;
}