/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** function that returns a number, sent to the function as a string
*/

int my_is_pos_getnbr(char const *str)
{
    int minus = 0;

    for (int i = 0; str[i] == '-' || str[i] == '+'; i += 1)
        minus += (str[i] == '-');
    if (minus % 2 == 0)
        return (1);
    return (-1);
}

int my_compute_power_rec(int nb, int p)
{
    if (p == 0) {
        return (1);
    }
    if (p < 0) {
        return (0);
    }
    return (nb * my_compute_power_rec(nb, p - 1));
}

int my_getnbr(char const *str)
{
    int number = 0;
    int pos;

    for (pos = 0; str[pos] == '-' || str[pos] == '+'; pos += 1);
    for (; '0' <= str[pos] && str[pos] <= '9'; pos += 1);
    for (int i = 0; pos != 0 && '0' <= str[pos - 1] && str[pos - 1] <= '9';
    i += 1) {
        number += (str[pos - 1] - '0') * my_compute_power_rec(10, i);
        pos -= 1;
    }
    return (number * (my_is_pos_getnbr(str)));
}
