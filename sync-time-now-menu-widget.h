#ifndef __SYNC_TIME_NOW_MENU_WIDGET_H__
#define __SYNC_TIME_NOW_MENU_WIDGET_H__
 
#include <libhildondesktop/libhildondesktop.h>
 
G_BEGIN_DECLS
 
#define TYPE_SYNC_TIME_NOW_MENU_WIDGET            (sync_time_now_menu_widget_get_type ())
 
#define SYNC_TIME_NOW_MENU_WIDGET(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
                                    TYPE_SYNC_TIME_NOW_MENU_WIDGET, SyncTimeNowMenuWidget))
 
#define SYNC_TIME_NOW_MENU_WIDGET_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), \
                                TYPE_SYNC_TIME_NOW_MENU_WIDGET, SyncTimeNowMenuWidgetClass))
 
#define IS_SYNC_TIME_NOW_MENU_WIDGET(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
                                                    TYPE_SYNC_TIME_NOW_MENU_WIDGET))
 
#define IS_SYNC_TIME_NOW_MENU_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), \
                                                    TYPE_SYNC_TIME_NOW_MENU_WIDGET))
 
#define SYNC_TIME_NOW_MENU_WIDGET_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), \
                            TYPE_SYNC_TIME_NOW_MENU_WIDGET, SyncTimeNowMenuWidgetClass))
 
#define STATUS_AREA_ICON_SIZE 22
 
typedef struct _SyncTimeNowMenuWidget        SyncTimeNowMenuWidget;
typedef struct _SyncTimeNowMenuWidgetClass   SyncTimeNowMenuWidgetClass;
typedef struct _SyncTimeNowMenuWidgetPrivate SyncTimeNowMenuWidgetPrivate; 
 
struct _SyncTimeNowMenuWidget
{
    HDStatusMenuItem parent;
 
    SyncTimeNowMenuWidgetPrivate *priv;
};
 
struct _SyncTimeNowMenuWidgetClass
{
    HDStatusMenuItemClass parent;
};
 
GType sync_time_now_menu_widget_get_type (void);
 
G_END_DECLS
 
#endif
