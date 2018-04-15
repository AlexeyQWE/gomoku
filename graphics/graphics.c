#include <stdio.h>
#include <stdlib.h>
#include "gtk/gtk.h"
gint delete_event( GtkWidget *widget,
                           GdkEvent  *event,
                           gpointer   data )
{
    gtk_main_quit ();
    return FALSE;
}
        /* Создаём контейнер hbox заполненный кнопками с ярлыками. 
         * Передаём функции интересующие аргументы.
         * Отображается только содержимое контейнера. */
GtkWidget *make_box( gboolean homogeneous,
                        gint     spacing,
                        gboolean expand,
                        gboolean fill,
                        guint    padding ) 
{
    GtkWidget *box;
    GtkWidget *button;
    char padstr[80];
    
    /* Создаём новый контейнер vbox соответствующий homogeneous
     * и установкам интервала */
    box = gtk_vbox_new (homogeneous, spacing);
    
    /* Создаём ряд кнопок с соответствующими параметрами */

    button = gtk_button_new_with_label ("Играть");
    gtk_box_pack_start (GTK_BOX (box), button, expand, fill, padding);
    gtk_widget_show (button);
    
    button = gtk_button_new_with_label ("Настройки");
    gtk_box_pack_start (GTK_BOX (box), button, expand, fill, padding);
    gtk_widget_show (button);
    
    button = gtk_button_new_with_label ("Правила");
    gtk_box_pack_start (GTK_BOX (box), button, expand, fill, padding);
    gtk_widget_show (button);

    button = gtk_button_new_with_label ("Зал Славы");
    gtk_box_pack_start (GTK_BOX (box), button, expand, fill, padding);
    gtk_widget_show (button);
    
    return box;
}
int main( int   argc,
          char *argv[]) 
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box1;
    GtkWidget *box2;
    GtkWidget *separator;
    GtkWidget *label;
    GtkWidget *quitbox;
    int which;
    
    /* Обязательный init, не забывайте об этом! :) */
    gtk_init (&argc, &argv);
    
    if (argc != 2) {
        fprintf (stderr, "usage: packbox num, where num is 1, 2, or 3.\n");
        /* Очищаем поток выхода GTK и выходим со статусом 1. */
        exit (1);
    }
    
    which = atoi (argv[1]);
    /* Создаём основное окно */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "GOMOKU");
    /* Нужно всегда подключать сигнал delete_event к основному окну
     * Это необходимо для интуитивного поведения */
    g_signal_connect (G_OBJECT (window), "delete_event",
                             G_CALLBACK (delete_event), NULL);
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    
    /* Создаём вертикальный контейнер (vbox) для упаковки в него горизонтальных контейнеров
     * Это позволяет располагать горизонтальные контейнеры с кнопками один над другим. */
    box1 = gtk_vbox_new (FALSE, 0);
    
    /* Демонстрация использования gtk_box_pack_end() для правого выравнивания виджетов.
     * Сначала создаём контейнер как и прежде*/

    box2 = make_box (FALSE, 0, FALSE, FALSE, 0);
        label = gtk_label_new ("");
    /* Упаковываем используя gtk_box_pack_end(), размещая таким образом
     * hbox созданный вызовом make_box() по правой стороне. */
    gtk_box_pack_end (GTK_BOX (box2), label, FALSE, FALSE, 0);
    /* Показываем ярлык */
    gtk_widget_show (label);
    /* Создаём ярлык, который будет размещён в конце */
    
    /* Упаковываем box2 в box1 (vbox помните ? :) */
    gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
    gtk_widget_show (box2);
    
    /* Сепаратор для основания. */
    separator = gtk_hseparator_new ();
    /* Явно определяем ширину сепаратора в 400 pixels и высоту в 5 pixels.
     * hbox который мы создали также будет 400 pixels в ширину,
     * а ярлык "end" будет отделен от других ярлыков в hbox.
     * Иначе все виджеты в hbox будут расположены вплотную друг к другу */
    gtk_widget_set_size_request (separator, 400, 5);
    /* упаковываем сепаратор в hbox (box1) созданный в начале main() */
    gtk_box_pack_start (GTK_BOX (box1), separator, FALSE, TRUE, 5);
    gtk_widget_show (separator);    

    /* Создаём новый vbox. Помните, их может быть столько - сколько нужно! */
    quitbox = gtk_hbox_new (FALSE, 0);
    
    /* Кнопка выхода. */
    button = gtk_button_new_with_label ("Выход");
    
    /* Устанавливаем сигнал для закрытия программы при нажатии кнопки */
    g_signal_connect_swapped (G_OBJECT (button), "clicked",
                              G_CALLBACK (gtk_main_quit),
                              G_OBJECT (window));
    /* Упаковываем кнопку в  quitbox.
     * Последние три аргумента gtk_box_pack_start are:
     * expand, fill, padding. */
    gtk_box_pack_start (GTK_BOX (quitbox), button, TRUE, FALSE, 0);
    /* Упаковываем quitbox в vbox (box1) */
    gtk_box_pack_start (GTK_BOX (box1), quitbox, FALSE, FALSE, 0);
    
    /* Упаковываем vbox (box1), который теперь содержит все наши виджеты, в главное окно. */
    gtk_container_add (GTK_CONTAINER (window), box1);
    
    /* Показываем всё остальное */
    gtk_widget_show (button);
    gtk_widget_show (quitbox);
    
    gtk_widget_show (box1);
    /* Последним выводим для отображения главное окно, таким образом всё отображается одновременно */
    gtk_widget_show (window);
    
    /* И конечно главная функция */
    gtk_main ();
    /* Сюда контроль попадает после вызова gtk_main_quit(),но не после использования exit(). */
    return 0;
}