#include <gtk/gtk.h>
#include "Operations_on_StringNumbrs.h"

int check_num_sign(char *number, GtkTextBuffer *buffer) // It returns whether the number is positive(0) or negative(1)
{
    long int length;
    bool isinteger = true;
    length = strlen(number);
    if (length == 0)
    {
        gtk_text_buffer_set_text(buffer, "!!! Invalid Input !!!\n    Try Again\n", 36);
        return -1;
    }
    int digits_count = 0;
    for (int i = 0; i < length; i++)
    {
        if (number[i] == '-' && i == 0)
            continue;
        if (!isdigit(number[i]))
        {
            isinteger = false;
            break;
        }
    }
    if (!isinteger)
    {
        gtk_text_buffer_set_text(buffer, "!!! Invalid Input !!!\n    Try Again\n", 36);
        return -1;
    }

    bool negative = false;
    if (number[0] == '-')
    {
        for (int i = 0; i < length + 1; i++)
            number[i] = number[i + 1];
        negative = true;
    }
    if (negative)
        return 1;
    else
        return 0;
}

void on_click(GtkButton *btn, gpointer userdata)
{
    GtkBuilder *builder = GTK_BUILDER(userdata);
    GtkStack * stack = GTK_STACK(gtk_builder_get_object(builder, "stack"));
    GtkFixed *fixed = GTK_FIXED(gtk_stack_get_visible_child(stack));
    const gchar *fixed_name = gtk_stack_get_visible_child_name(stack);
    GtkTextBuffer *buffer = GTK_TEXT_BUFFER(gtk_builder_get_object(builder, "textbuffer1"));
    GtkTextIter start, end;
    g_print("%s\n", fixed_name);
    GtkEntry *entry1, *entry2;
    GtkLabel *operation;
    char *result;
    if (g_strcmp0(fixed_name, "Multiplication") == 0)
    {
        entry1 = GTK_ENTRY(gtk_builder_get_object(builder, "entry1"));
        entry2 = GTK_ENTRY(gtk_builder_get_object(builder, "entry2"));
        operation = GTK_LABEL(gtk_builder_get_object(builder, "mlabel"));
        const gchar *op_text = gtk_label_get_text(operation);
        gchar *num1 = g_strdup((gchar *)gtk_entry_get_text(entry1));
        gchar *num2 = g_strdup((gchar *)gtk_entry_get_text(entry2));
        int num1_negative = check_num_sign(num1, buffer);
        if (num1_negative == -1)
        {
            g_free(num1);
            g_free(num2);
            return;
        }
        int num2_negative = check_num_sign(num2, buffer);
        if (num2_negative == -1)
        {
            g_free(num1);
            g_free(num2);
            return;
        }
        g_print("%s\n%s\n", num1, num2);
        result = multiply((char *)num1, num1_negative, (char *)num2, num2_negative);
        gtk_text_buffer_set_text(buffer, (const gchar *)result, (gint)strlen(result));
        g_free(num1);
        g_free(num2);
    }
    else if (g_strcmp0(fixed_name, "Power") == 0)
    {
        entry1 = GTK_ENTRY(gtk_builder_get_object(builder, "entry3"));
        entry2 = GTK_ENTRY(gtk_builder_get_object(builder, "entry4"));
        operation = GTK_LABEL(gtk_builder_get_object(builder, "plabel"));
        const gchar *op_text = gtk_label_get_text(operation);
        gchar *num1 = g_strdup((gchar *)gtk_entry_get_text(entry1));
        gchar *num2 = g_strdup((gchar *)gtk_entry_get_text(entry2));
        int num1_negative = check_num_sign(num1, buffer);
        if (num1_negative == -1)
        {
            g_free(num1);
            g_free(num2);
            return;
        }
        int num2_negative = check_num_sign(num2, buffer);
        if (num2_negative == -1)
        {
            g_free(num1);
            g_free(num2);
            return;
        }
        if (num2_negative == 1)
        {
            gtk_text_buffer_set_text(buffer, "Power Can't Be Negative\n", 24);
            g_free(num1);
            g_free(num2);
            return;
        }
        g_print("%s\n%s\n", num1, num2);
        result = mypow(num1, atol(num2), num1_negative);
        gtk_text_buffer_set_text(buffer, (const gchar *)result, (gint)strlen(result));
        g_free(num1);
        g_free(num2);
    }
    else if (g_strcmp0(fixed_name, "Addition") == 0)
    {
        entry1 = GTK_ENTRY(gtk_builder_get_object(builder, "entry5"));
        entry2 = GTK_ENTRY(gtk_builder_get_object(builder, "entry6"));
        operation = GTK_LABEL(gtk_builder_get_object(builder, "alabel"));
        const gchar *op_text = gtk_label_get_text(operation);
        gchar *num1 = g_strdup((gchar *)gtk_entry_get_text(entry1));
        gchar *num2 = g_strdup((gchar *)gtk_entry_get_text(entry2));
        int num1_negative = check_num_sign(num1, buffer);
        if (num1_negative == -1)
        {
            g_free(num1);
            g_free(num2);
            return;
        }
        int num2_negative = check_num_sign(num2, buffer);
        if (num2_negative == -1)
        {
            g_free(num1);
            g_free(num2);
            return;
        }
        g_print("%s\n%s\n", num1, num2);
        result = add_signed(num1, num1_negative, num2, num2_negative);
        gtk_text_buffer_set_text(buffer, (const gchar *)result, (gint)strlen(result));
        g_free(num1);
        g_free(num2);
    }
    else if (g_strcmp0(fixed_name, "Subtraction") == 0)
    {
        entry1 = GTK_ENTRY(gtk_builder_get_object(builder, "entry7"));
        entry2 = GTK_ENTRY(gtk_builder_get_object(builder, "entry8"));
        operation = GTK_LABEL(gtk_builder_get_object(builder, "slabel"));
        const gchar *op_text = gtk_label_get_text(operation);
        gchar *num1 = g_strdup((gchar *)gtk_entry_get_text(entry1));
        gchar *num2 = g_strdup((gchar *)gtk_entry_get_text(entry2));
        int num1_negative = check_num_sign(num1, buffer);
        if (num1_negative == -1)
        {
            g_free(num1);
            g_free(num2);
            return;
        }
        int num2_negative = check_num_sign(num2, buffer);
        if (num2_negative == -1)
        {
            g_free(num1);
            g_free(num2);
            return;
        }
        g_print("%s\n%s\n", num1, num2);
        result = subtract(num1, num1_negative, num2, num2_negative);
        gtk_text_buffer_set_text(buffer, (const gchar *)result, (gint)strlen(result));
        g_free(num1);
        g_free(num2);
    }
    free(result);
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    GtkBuilder *builder = gtk_builder_new();
    if (!gtk_builder_add_from_file(builder, "Arithmetics.glade", NULL))
    {
        g_print("An Error occurred while openning glade file !!\n");
        return EXIT_FAILURE;
    }
    GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    GtkButton *calculate_button = GTK_BUTTON(gtk_builder_get_object(builder, "calculate_button"));
    GtkStack *stack = GTK_STACK(gtk_builder_get_object(builder, "stack"));
    g_signal_connect(calculate_button, "clicked", G_CALLBACK(on_click), g_object_ref(builder));


    gtk_widget_show_all(window);
    gtk_main();
    g_object_unref(builder);
    return EXIT_SUCCESS;
}