def find_item(items, condition):
    for idx, item in enumerate(items):
        if condition(item):
            return item, idx

    return None, -1