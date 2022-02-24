using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Text;

namespace СonsoleExplorer
{
    internal class Program
    {
        private static bool _run = true;
        private static string[] _drives;
        private static int _currentDrive = 0;
        private static List<DirectoryInfo> _dirs;
        private static FileInfo[] _files;
        private static DirectoryInfo _currentDir;
        private static string _path;

        //static FileSystemInfo[] _content;
        private static int _choice;

        private static bool IsRoot()
        {
            return _path == $"{_drives[_currentDrive]}";
        }

        private static void ShowDrives()
        {
            for (int i = 0; i < _drives.Length; i++)
            {
                if (i == _currentDrive)
                {
                    Console.ForegroundColor = ConsoleColor.DarkGray;
                    Console.BackgroundColor = ConsoleColor.White;
                }

                Console.Write("    ");
                Console.Write(_drives[i].TrimEnd(Path.DirectorySeparatorChar));

                Console.ForegroundColor = ConsoleColor.White;
                Console.BackgroundColor = ConsoleColor.DarkGray;
            }
            Console.WriteLine("\n");
        }

        private static void ShowContent()
        {
            int dirIndex = 0;
            if (_dirs[0].FullName == GetPreviousDir())
            {
                if (0 == _choice)
                {
                    Console.ForegroundColor = ConsoleColor.DarkGray;
                    Console.BackgroundColor = ConsoleColor.White;
                }
                Console.WriteLine("..");
                Console.ForegroundColor = ConsoleColor.White;
                Console.BackgroundColor = ConsoleColor.DarkGray;
                dirIndex = 1;
            }

            for (int i = dirIndex; i < _dirs.Count; i++)
            {
                if (i == _choice)
                {
                    Console.ForegroundColor = ConsoleColor.DarkGray;
                    Console.BackgroundColor = ConsoleColor.White;
                }
                Console.WriteLine(_dirs[i].Name);
                Console.ForegroundColor = ConsoleColor.White;
                Console.BackgroundColor = ConsoleColor.DarkGray;
            }

            for (int i = 0; i < _files.Length; i++)
            {
                if (i == _choice - _dirs.Count)
                {
                    Console.ForegroundColor = ConsoleColor.DarkGray;
                    Console.BackgroundColor = ConsoleColor.White;
                }
                Console.WriteLine(_files[i].Name);
                Console.ForegroundColor = ConsoleColor.White;
                Console.BackgroundColor = ConsoleColor.DarkGray;
            }
        }

        private static void UpdateContent()
        {
            _dirs.Clear();
            if (!IsRoot())
            {
                _dirs.Add(new DirectoryInfo(GetPreviousDir()));
            }
            _dirs.AddRange(_currentDir.GetDirectories());
            _files = _currentDir.GetFiles();
        }

        private static string GetPreviousDir()
        {
            if (_path == $"{_drives[_currentDrive]}")
            {
                return $"{_drives[_currentDrive]}";
            }
            int slashIndex = _path.Length - 2;
            while (_path[slashIndex] != '\\')
            {
                slashIndex--;
            }
            int count = _path.Length - slashIndex + 1;
            return _path.Remove(slashIndex + 1, count - 2);
        }

        public static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            Console.ForegroundColor = ConsoleColor.White;
            Console.BackgroundColor = ConsoleColor.DarkGray;

            _drives = Directory.GetLogicalDrives();
            _path = $"{_drives[_currentDrive]}";
            _dirs = new List<DirectoryInfo>();

            while (_run)
            {
                Console.Clear();
                _drives = Directory.GetLogicalDrives();
                ShowDrives();
                _currentDir = new DirectoryInfo(_path);

                UpdateContent();
                ShowContent();

                switch (Console.ReadKey().Key)
                {
                    case ConsoleKey.Escape:
                        _run = false;
                        break;

                    case ConsoleKey.LeftArrow:
                        --_currentDrive;
                        if (_currentDrive < 0) { _currentDrive = 0; }
                        _path = $"{_drives[_currentDrive]}";
                        break;

                    case ConsoleKey.RightArrow:
                        ++_currentDrive;
                        if (_currentDrive >= _drives.Length) { _currentDrive = _drives.Length - 1; }
                        _path = $"{_drives[_currentDrive]}";
                        break;

                    case ConsoleKey.UpArrow:
                        --_choice;
                        break;

                    case ConsoleKey.DownArrow:
                        ++_choice;
                        break;

                    case ConsoleKey.Enter:
                        if (_choice < _dirs.Count)
                        {
                            _path = _dirs[_choice].FullName;
                        }
                        else
                        {
                            Process.Start(_files[_choice - _dirs.Count].FullName);
                        }
                        break;
                }

                if (_choice < 0) { _choice = 0; }
                else if (_choice > _dirs.Count + _files.Length)
                {
                    _choice = _dirs.Count + _files.Length - 1;
                }
            }
        }
    }
}