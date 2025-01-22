char    ft_f(unsigned int index, char chara)
{
    if (index == 255)
        return ('0');
    if (ft_islower(chara))
        return (chara - 32);
    return (chara);
}
