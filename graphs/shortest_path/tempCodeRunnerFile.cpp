printing path from source to destination
        cout << "\nPath is:\n";
        for (int i = path.size() - 1; i >= 0; i--)
            cout << char(path[i] + 65) << " ";