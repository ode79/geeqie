/*
 * Geeqie
 * Copyright (C) 2008 The Geeqie Team
 *
 * Author: Laurent Monin
 *
 * This software is released under the GNU General Public License (GNU GPL).
 * Please read the included file COPYING for more information.
 * This software comes with no warranty of any kind, use at your own risk!
 */

#include "main.h"
#include "view_file.h"

#include "debug.h"
#include "view_file_list.h"
#include "view_file_icon.h"


/*
 *-----------------------------------------------------------------------------
 * misc
 *-----------------------------------------------------------------------------
 */

void vf_sort_set(ViewFile *vf, SortType type, gint ascend)
{
	switch(vf->type)
	{
	case FILEVIEW_LIST: vflist_sort_set(vf, type, ascend); break;
	case FILEVIEW_ICON: vficon_sort_set(vf, type, ascend); break;
	}
}

/*
 *-----------------------------------------------------------------------------
 * row stuff
 *-----------------------------------------------------------------------------
 */

FileData *vf_index_get_data(ViewFile *vf, gint row)
{
	FileData *fd = NULL;

	switch(vf->type)
	{
	case FILEVIEW_LIST: fd = vflist_index_get_data(vf, row); break;
	case FILEVIEW_ICON: fd = vficon_index_get_data(vf, row); break;
	}

	return fd;
}

gchar *vf_index_get_path(ViewFile *vf, gint row)
{
	gchar *path = NULL;
	
	switch(vf->type)
	{
	case FILEVIEW_LIST: path = vflist_index_get_path(vf, row); break;
	case FILEVIEW_ICON: path = vficon_index_get_path(vf, row); break;
	}

	return path;
}

gint vf_index_by_path(ViewFile *vf, const gchar *path)
{
	gint index = -1;

	switch(vf->type)
	{
	case FILEVIEW_LIST: index = vflist_index_by_path(vf, path); break;
	case FILEVIEW_ICON: index = vficon_index_by_path(vf, path); break;
	}

	return index;
}

gint vf_count(ViewFile *vf, gint64 *bytes)
{
	gint count = 0;

	switch(vf->type)
	{
	case FILEVIEW_LIST: count = vflist_count(vf, bytes); break;
	case FILEVIEW_ICON: count = vficon_count(vf, bytes); break;
	}

	return count;
}

GList *vf_get_list(ViewFile *vf)
{
	GList *list = NULL;

	switch(vf->type)
	{
	case FILEVIEW_LIST: list = vflist_get_list(vf); break;
	case FILEVIEW_ICON: list = vficon_get_list(vf); break;
	}

	return list;
}


/*
 *-------------------------------------------------------------------
 * keyboard
 *-------------------------------------------------------------------
 */

static gint vf_press_key_cb(GtkWidget *widget, GdkEventKey *event, gpointer data)
{
	ViewFile *vf = data;
	gint ret = FALSE;

	switch(vf->type)
	{
	case FILEVIEW_LIST: ret = vflist_press_key_cb(widget, event, data); break;
	case FILEVIEW_ICON: ret = vficon_press_key_cb(widget, event, data); break;
	}

	return ret;
}

/*
 *-------------------------------------------------------------------
 * mouse
 *-------------------------------------------------------------------
 */

static gint vf_press_cb(GtkWidget *widget, GdkEventButton *bevent, gpointer data)
{
	ViewFile *vf = data;
	gint ret = FALSE;

	switch(vf->type)
	{
	case FILEVIEW_LIST: ret = vflist_press_cb(widget, bevent, data); break;
	case FILEVIEW_ICON: ret = vficon_press_cb(widget, bevent, data); break;
	}

	return ret;
}

static gint vf_release_cb(GtkWidget *widget, GdkEventButton *bevent, gpointer data)
{
	ViewFile *vf = data;
	gint ret = FALSE;

	switch(vf->type)
	{
	case FILEVIEW_LIST: ret = vflist_release_cb(widget, bevent, data); break;
	case FILEVIEW_ICON: ret = vficon_release_cb(widget, bevent, data); break;
	}

	return ret;
}


/*
 *-----------------------------------------------------------------------------
 * selections
 *-----------------------------------------------------------------------------
 */

gint vf_selection_count(ViewFile *vf, gint64 *bytes)
{
	gint count = 0;

	switch(vf->type)
	{
	case FILEVIEW_LIST: count = vflist_selection_count(vf, bytes); break;
	case FILEVIEW_ICON: count = vficon_selection_count(vf, bytes); break;
	}

	return count;
}

GList *vf_selection_get_list(ViewFile *vf)
{
	GList *list = NULL;

	switch(vf->type)
	{
	case FILEVIEW_LIST: list = vflist_selection_get_list(vf); break;
	case FILEVIEW_ICON: list = vficon_selection_get_list(vf); break;
	}

	return list;
}

GList *vf_selection_get_list_by_index(ViewFile *vf)
{
	GList *list = NULL;

	switch(vf->type)
	{
	case FILEVIEW_LIST: list = vflist_selection_get_list_by_index(vf); break;
	case FILEVIEW_ICON: list = vficon_selection_get_list_by_index(vf); break;
	}

	return list;
}

void vf_select_all(ViewFile *vf)
{
	switch(vf->type)
	{
	case FILEVIEW_LIST: vflist_select_all(vf); break;
	case FILEVIEW_ICON: vficon_select_all(vf); break;
	}
}

void vf_select_none(ViewFile *vf)
{
	switch(vf->type)
	{
	case FILEVIEW_LIST: vflist_select_none(vf); break;
	case FILEVIEW_ICON: vficon_select_none(vf); break;
	}
}

void vf_select_by_fd(ViewFile *vf, FileData *fd)
{
	switch(vf->type)
	{
	case FILEVIEW_LIST: vflist_select_by_fd(vf, fd); break;
	case FILEVIEW_ICON: vficon_select_by_fd(vf, fd); break;
	}
}

void vf_mark_to_selection(ViewFile *vf, gint mark, MarkToSelectionMode mode)
{
	switch(vf->type)
	{
	case FILEVIEW_LIST: vflist_mark_to_selection(vf, mark, mode); break;
	case FILEVIEW_ICON: vficon_mark_to_selection(vf, mark, mode); break;
	}
}

void vf_selection_to_mark(ViewFile *vf, gint mark, SelectionToMarkMode mode)
{
	switch(vf->type)
	{
	case FILEVIEW_LIST: vflist_selection_to_mark(vf, mark, mode); break;
	case FILEVIEW_ICON: vficon_selection_to_mark(vf, mark, mode); break;
	}
}

/*
 *-----------------------------------------------------------------------------
 * dnd
 *-----------------------------------------------------------------------------
 */


static void vf_dnd_init(ViewFile *vf)
{
	switch(vf->type)
	{
	case FILEVIEW_LIST: vflist_dnd_init(vf); break;
	case FILEVIEW_ICON: vficon_dnd_init(vf); break;
	}
}

gint vf_refresh(ViewFile *vf)
{
	gint ret = FALSE;

	switch(vf->type)
	{
	case FILEVIEW_LIST: ret = vflist_refresh(vf); break;
	case FILEVIEW_ICON: ret = vficon_refresh(vf); break;
	}

	return ret;
}

gint vf_set_path(ViewFile *vf, const gchar *path)
{
	gint ret = FALSE;

	switch(vf->type)
	{
	case FILEVIEW_LIST: ret = vflist_set_path(vf, path); break;
	case FILEVIEW_ICON: ret = vficon_set_path(vf, path); break;
	}
	
	return ret;
}

static void vf_destroy_cb(GtkWidget *widget, gpointer data)
{
	ViewFile *vf = data;

	switch(vf->type)
	{
	case FILEVIEW_LIST: vflist_destroy_cb(widget, data); break;
	case FILEVIEW_ICON: vficon_destroy_cb(widget, data); break;
	}

	if (vf->popup)
		{
		g_signal_handlers_disconnect_matched(G_OBJECT(vf->popup), G_SIGNAL_MATCH_DATA,
						     0, 0, 0, NULL, vf);
		gtk_widget_destroy(vf->popup);
		}

	g_free(vf->path);
	g_free(vf->info);
	g_free(vf);
}

ViewFile *vf_new(FileViewType type, const gchar *path)
{
	ViewFile *vf;

	vf = g_new0(ViewFile, 1);
	vf->type = type;

	vf->info = NULL;
	vf->path = NULL;
	vf->list = NULL;

	vf->sort_method = SORT_NAME;
	vf->sort_ascend = TRUE;
	
	vf->thumbs_running = FALSE;
	vf->thumbs_count = 0;
	vf->thumbs_loader = NULL;
	vf->thumbs_filedata = NULL;

	vf->popup = NULL;

	vf->widget = gtk_scrolled_window_new(NULL, NULL);
	gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(vf->widget), GTK_SHADOW_IN);
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(vf->widget),
				       GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	
	g_signal_connect(G_OBJECT(vf->widget), "destroy",
			 G_CALLBACK(vf_destroy_cb), vf);

	switch(type)
	{
	case FILEVIEW_LIST: vf = vflist_new(vf, path); break;
	case FILEVIEW_ICON: vf = vficon_new(vf, path); break;
	}

	vf_dnd_init(vf);

	g_signal_connect(G_OBJECT(vf->listview), "key_press_event",
			 G_CALLBACK(vf_press_key_cb), vf);
	g_signal_connect(G_OBJECT(vf->listview), "button_press_event",
			 G_CALLBACK(vf_press_cb), vf);
	g_signal_connect(G_OBJECT(vf->listview), "button_release_event",
			 G_CALLBACK(vf_release_cb), vf);

	gtk_container_add(GTK_CONTAINER(vf->widget), vf->listview);
	gtk_widget_show(vf->listview);

	if (path) vf_set_path(vf, path);

	return vf;
}

void vf_set_status_func(ViewFile *vf, void (*func)(ViewFile *vf, gpointer data), gpointer data)
{
	vf->func_status = func;
	vf->data_status = data;
}

void vf_set_thumb_status_func(ViewFile *vf, void (*func)(ViewFile *vf, gdouble val, const gchar *text, gpointer data), gpointer data)
{
	vf->func_thumb_status = func;
	vf->data_thumb_status = data;
}

void vf_thumb_set(ViewFile *vf, gint enable)
{
	switch(vf->type)
	{
	case FILEVIEW_LIST: vflist_thumb_set(vf, enable); break;
	case FILEVIEW_ICON: /*vficon_thumb_set(vf, enable);*/ break;
	}
}

void vf_marks_set(ViewFile *vf, gint enable)
{
	switch(vf->type)
	{
	case FILEVIEW_LIST: vflist_marks_set(vf, enable); break;
	case FILEVIEW_ICON: /*vficon_marks_set(vf, enable);*/ break;
	}
}

void vf_set_layout(ViewFile *vf, LayoutWindow *layout)
{
	vf->layout = layout;
}

/*
 *-----------------------------------------------------------------------------
 * maintenance (for rename, move, remove)
 *-----------------------------------------------------------------------------
 */

gint vf_maint_renamed(ViewFile *vf, FileData *fd)
{
	gint ret = FALSE;

	switch(vf->type)
	{
	case FILEVIEW_LIST: ret = vflist_maint_renamed(vf, fd); break;
	case FILEVIEW_ICON: ret = vficon_maint_renamed(vf, fd); break;
	}

	return ret;
}

gint vf_maint_removed(ViewFile *vf, FileData *fd, GList *ignore_list)
{
	gint ret = FALSE;

	switch(vf->type)
	{
	case FILEVIEW_LIST: ret = vflist_maint_removed(vf, fd, ignore_list); break;
	case FILEVIEW_ICON: ret = vficon_maint_removed(vf, fd, ignore_list); break;
	}

	return ret;
}

gint vf_maint_moved(ViewFile *vf, FileData *fd, GList *ignore_list)
{
	gint ret = FALSE;

	switch(vf->type)
	{
	case FILEVIEW_LIST: ret = vflist_maint_moved(vf, fd, ignore_list); break;
	case FILEVIEW_ICON: ret = vficon_maint_moved(vf, fd, ignore_list); break;
	}

	return ret;
}