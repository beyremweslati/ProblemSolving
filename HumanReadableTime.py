def format_duration(seconds):
    if seconds == 0:
        return "now"
    if seconds >= (365 * 86400):
        years = seconds // (365 * 86400)
        seconds = seconds - (years * (365 * 86400))
        year_str = "1 year" if years == 1 else str(years) + " years"
    else:
        year_str = ""

    if seconds >= 86400:
        days = seconds // 86400
        seconds = seconds - (days * 86400)
        day_str = "1 day" if days == 1 else str(days) + " days"
    else:
        day_str = ""

    if seconds >= 3600:
        hours = seconds // 3600
        seconds = seconds - (3600 * hours)
        hour_str = "1 hour" if hours == 1 else str(hours) + " hours"
    else:
        hour_str = ""

    if seconds >= 60:
        minutes = seconds // 60
        seconds = seconds - (60 * minutes)
        minute_str = "1 minute" if minutes == 1 else str(minutes) + " minutes"
    else:
        minute_str = ""
    if seconds > 0:
        second_str = "1 second" if seconds == 1 else str(seconds) + " seconds"
    else:
        second_str = ""
    lst = [part for part in [year_str, day_str, hour_str, minute_str, second_str] if part]

    if len(lst) == 1:
        return lst[0]
    elif len(lst) == 2:
        return lst[0] + " and "  + lst[1]
    else:
        return ', '.join(lst[:-1]) + " and " + lst[-1]

print(format_duration(48612335))