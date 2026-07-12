def find_item(items, condition):

    for index, item in enumerate(items):

        if condition(item):
            return item, index

    return None, -1