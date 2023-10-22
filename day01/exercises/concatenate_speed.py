def ft_concatenate_speed_up(l_strings, d):
    """concatenate list of strings into one string separated by delimiter"""
    return d.join(string for string in l_strings)
