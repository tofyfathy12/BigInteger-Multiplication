#include <gtk/gtk.h>
#include "BigNumbersArithmetics.c"

void on_click(GtkButton *btn, gpointer userdata)
{
    GtkStack *stack = GTK_STACK(userdata);
    GtkFixed *fixed = GTK_FIXED(gtk_stack_get_visible_child(stack));
    const gchar *fixed_name = gtk_stack_get_visible_child_name(stack);
    g_print("%s\n", fixed_name);
    GList *children = gtk_container_get_children(GTK_CONTAINER(fixed));
    GtkEntry *entry1, *entry2;
    GtkLabel *operation;
    int i = 0;
    for (GList *iter = children; iter != NULL; iter = iter->next)
    {
        switch (i)
        {
            case 1:
                entry1 = GTK_ENTRY(iter->data);
                break;
            case 2:
                entry2 = GTK_ENTRY(iter->data);
                break;
            case 3:
                operation = GTK_ENTRY(iter->data);
                break;
            default:
                g_print("ERROR HAPPENED AT LINE BETWEEN %d AND %d\n", __LINE__ - 10, __LINE__);
        }
        i++;
    }
    const gchar *op_text = gtk_label_get_text(operation);
    gchar *num1 = gtk_entry_get_text(entry1);
    gchar *num2 = gtk_entry_get_text(entry2);
    if (op_text[0] == 'X')
    {

    }
    else if (op_text[0] == '^')
    {

    }
    else if (op_text[0] == '+')
    {

    }
    else if (op_text[0] == '-')
    {

    }

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
    g_signal_connect(calculate_button, "clicked", G_CALLBACK(on_click), stack);


    gtk_widget_show_all(window);
    gtk_main();
    g_object_unref(builder);
    return EXIT_SUCCESS;
}