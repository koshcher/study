using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;

namespace firstConnecting
{
    class Program
    {
        SqlConnection conn = null;
        public Program()
        {
            conn = new SqlConnection("Data Source=(localdb)\\ProjectsV13;Initial Catalog=Books;Integrated Security=True;Connect Timeout=30;Encrypt=False;TrustServerCertificate=False;ApplicationIntent=ReadWrite;MultiSubnetFailover=False");
        }

        static void Main(string[] args)
        {
            Program pr = new Program();
            pr.ReadData();
            pr.InsertQuery();

            Console.ReadKey();
        }

        public void InsertQuery()
        {
            try
            {
                //открыть соединение
                conn.Open();
                //подготовить запрос insert
                //в переменной типа string
                string insertString = @"insert into
                                        Authors (FirstName, LastName)
                                        values ('Roger', 'Zelazny')";
                //создать объект command,
                //инициализировав оба свойства
                SqlCommand cmd = new SqlCommand(insertString, conn);
                //выполнить запрос, занесенный
                //в объект command
                cmd.ExecuteNonQuery();
            }
            finally
            {
                // закрыть соединение
                if (conn != null)
                {
                    conn.Close();
                }
            }
        }

        public void ReadData()
        {
            string command = "select * from Authors";
            SqlCommand cmd = new SqlCommand(command, conn);
            SqlDataReader dr = null;
            try
            {
                conn.Open();
                dr = cmd.ExecuteReader();
                while(dr.Read())
                {
                    Console.WriteLine(dr[1] + " " + dr[2]);
                }

            }
            catch(Exception)
            {
                throw;
            }
            finally
            {
                // закрыть соединение
                if (conn != null)
                {
                    conn.Close();
                }
            }
        }
    }
}
