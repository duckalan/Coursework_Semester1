using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace Utility
{
    public static class BinaryFileManager
    {
        /// <summary>
        /// Загрузить файл в бинарном формате по пути <paramref name="filepath"/>  
        /// и получить объект типа <typeparamref name="T"/>.
        /// </summary>
        public static T Load<T>(string filepath)
        {
            try
            {
                var formatter = new BinaryFormatter();
                using (var fs = new FileStream(filepath, FileMode.Open))
                {
                    return (T)formatter.Deserialize(fs);
                }
            }
            catch (Exception)
            {
                return default;
            }
        }

        /// <summary>
        /// Сохранить объект <paramref name="obj"/> типа <typeparamref name="T"/>
        /// в бинарный файл по пути <paramref name="filepath"/>
        /// </summary>
        public static void Save<T>(string filepath, T obj)
        {
            var formatter = new BinaryFormatter();
            using (var fs = new FileStream(filepath, FileMode.Create))
            {
                formatter.Serialize(fs, obj);
            }
        }
    }
}
