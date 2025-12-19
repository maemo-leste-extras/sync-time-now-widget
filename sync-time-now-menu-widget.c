#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <hildon/hildon.h>
#include <time.h>
#include <clockd/libtime.h>
 
#include "sync-time-now-menu-widget.h"
 
#define SYNC_TIME_NOW_MENU_WIDGET_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE (obj,   \
                            TYPE_SYNC_TIME_NOW_MENU_WIDGET, SyncTimeNowMenuWidgetPrivate))
 
struct _SyncTimeNowMenuWidgetPrivate
{
    GtkWidget *label;
    gpointer data;
};
 
HD_DEFINE_PLUGIN_MODULE (SyncTimeNowMenuWidget, sync_time_now_menu_widget,   HD_TYPE_STATUS_MENU_ITEM);
 
static void
sync_time_now_menu_widget_class_finalize (SyncTimeNowMenuWidgetClass *klass) {}
 
static void
sync_time_now_menu_widget_class_init (SyncTimeNowMenuWidgetClass *klass)
{
    g_type_class_add_private (klass, sizeof (SyncTimeNowMenuWidgetPrivate));
}


static void button_clicked_callback( GtkWidget *widget, gpointer   data )
{
  system("sudo /usr/bin/rdate -s -n pool.ntp.org"); //this set time
  time_set_time(time_get_time());     //this refresh clock
}


static void
sync_time_now_menu_widget_init (SyncTimeNowMenuWidget *plugin)
{
    plugin->priv = SYNC_TIME_NOW_MENU_WIDGET_GET_PRIVATE (plugin);
 
    GtkIconTheme *icon_theme = gtk_icon_theme_get_default ();
    GList *list = gtk_icon_theme_list_icons (icon_theme, NULL);
    GdkPixbuf *pixbufClock = gtk_icon_theme_load_icon (icon_theme, "clock_day_time",
                    HILDON_ICON_PIXEL_SIZE_FINGER, GTK_ICON_LOOKUP_FORCE_SIZE, NULL);
    GdkPixbuf *pixbufSync = gtk_icon_theme_load_icon (icon_theme, "general_synchronization",
                    HILDON_ICON_PIXEL_SIZE_FINGER, GTK_ICON_LOOKUP_FORCE_SIZE, NULL);
    gdk_pixbuf_composite(pixbufSync, pixbufClock, 0, 0, HILDON_ICON_PIXEL_SIZE_FINGER, HILDON_ICON_PIXEL_SIZE_FINGER, HILDON_ICON_PIXEL_SIZE_FINGER / 4.0, HILDON_ICON_PIXEL_SIZE_FINGER / 4.0 - 1, 0.5, 0.5, GDK_INTERP_BILINEAR, 255);
    GtkWidget *buttonIcon = gtk_image_new_from_pixbuf(pixbufClock);
 
    GtkWidget *b = hildon_button_new_with_text(HILDON_SIZE_AUTO, HILDON_BUTTON_ARRANGEMENT_VERTICAL, "Sync clock now", NULL);
    hildon_button_set_image(HILDON_BUTTON(b), buttonIcon);
    hildon_button_set_alignment(HILDON_BUTTON(b), 0.0, 0.0, 1.0, 1.0);
    g_object_unref (pixbufClock);
    g_object_unref (pixbufSync);
    gtk_signal_connect (GTK_OBJECT (b), "clicked",
                        GTK_SIGNAL_FUNC (button_clicked_callback), NULL);

    hd_status_plugin_item_set_status_area_icon(HD_STATUS_PLUGIN_ITEM(plugin), NULL);

    gtk_widget_show_all (b);
 
    plugin->priv->label = b;
 
    gtk_container_add (GTK_CONTAINER (plugin), plugin->priv->label);
 
    gtk_widget_show_all (plugin->priv->label);
 
   gtk_widget_show (GTK_WIDGET (plugin));
}

