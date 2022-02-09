﻿#pragma warning disable 1591
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace CountriesApp
{
	using System.Data.Linq;
	using System.Data.Linq.Mapping;
	using System.Data;
	using System.Collections.Generic;
	using System.Reflection;
	using System.Linq;
	using System.Linq.Expressions;
	using System.ComponentModel;
	using System;
	
	
	[global::System.Data.Linq.Mapping.DatabaseAttribute(Name="CountriesDB")]
	public partial class DataClasses1DataContext : System.Data.Linq.DataContext
	{
		
		private static System.Data.Linq.Mapping.MappingSource mappingSource = new AttributeMappingSource();
		
    #region Extensibility Method Definitions
    partial void OnCreated();
    partial void InsertCountry(Country instance);
    partial void UpdateCountry(Country instance);
    partial void DeleteCountry(Country instance);
    partial void InsertMajorCity(MajorCity instance);
    partial void UpdateMajorCity(MajorCity instance);
    partial void DeleteMajorCity(MajorCity instance);
    partial void InsertRegion(Region instance);
    partial void UpdateRegion(Region instance);
    partial void DeleteRegion(Region instance);
    #endregion
		
		public DataClasses1DataContext() : 
				base(global::CountriesApp.Properties.Settings.Default.CountriesDBConnectionString, mappingSource)
		{
			OnCreated();
		}
		
		public DataClasses1DataContext(string connection) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public DataClasses1DataContext(System.Data.IDbConnection connection) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public DataClasses1DataContext(string connection, System.Data.Linq.Mapping.MappingSource mappingSource) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public DataClasses1DataContext(System.Data.IDbConnection connection, System.Data.Linq.Mapping.MappingSource mappingSource) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public System.Data.Linq.Table<Country> Countries
		{
			get
			{
				return this.GetTable<Country>();
			}
		}
		
		public System.Data.Linq.Table<MajorCity> MajorCities
		{
			get
			{
				return this.GetTable<MajorCity>();
			}
		}
		
		public System.Data.Linq.Table<Region> Regions
		{
			get
			{
				return this.GetTable<Region>();
			}
		}
	}
	
	[global::System.Data.Linq.Mapping.TableAttribute(Name="dbo.Countries")]
	public partial class Country : INotifyPropertyChanging, INotifyPropertyChanged
	{
		
		private static PropertyChangingEventArgs emptyChangingEventArgs = new PropertyChangingEventArgs(String.Empty);
		
		private int _Id;
		
		private string _Name;
		
		private int _CountCitizens;
		
		private int _Square;
		
		private int _Region;
		
		private EntitySet<MajorCity> _MajorCities;
		
		private EntityRef<Region> _Region1;
		
    #region Extensibility Method Definitions
    partial void OnLoaded();
    partial void OnValidate(System.Data.Linq.ChangeAction action);
    partial void OnCreated();
    partial void OnIdChanging(int value);
    partial void OnIdChanged();
    partial void OnNameChanging(string value);
    partial void OnNameChanged();
    partial void OnCountCitizensChanging(int value);
    partial void OnCountCitizensChanged();
    partial void OnSquareChanging(int value);
    partial void OnSquareChanged();
    partial void OnRegionChanging(int value);
    partial void OnRegionChanged();
    #endregion
		
		public Country()
		{
			this._MajorCities = new EntitySet<MajorCity>(new Action<MajorCity>(this.attach_MajorCities), new Action<MajorCity>(this.detach_MajorCities));
			this._Region1 = default(EntityRef<Region>);
			OnCreated();
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_Id", AutoSync=AutoSync.OnInsert, DbType="Int NOT NULL IDENTITY", IsPrimaryKey=true, IsDbGenerated=true)]
		public int Id
		{
			get
			{
				return this._Id;
			}
			set
			{
				if ((this._Id != value))
				{
					this.OnIdChanging(value);
					this.SendPropertyChanging();
					this._Id = value;
					this.SendPropertyChanged("Id");
					this.OnIdChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_Name", DbType="NVarChar(50) NOT NULL", CanBeNull=false)]
		public string Name
		{
			get
			{
				return this._Name;
			}
			set
			{
				if ((this._Name != value))
				{
					this.OnNameChanging(value);
					this.SendPropertyChanging();
					this._Name = value;
					this.SendPropertyChanged("Name");
					this.OnNameChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_CountCitizens", DbType="Int NOT NULL")]
		public int CountCitizens
		{
			get
			{
				return this._CountCitizens;
			}
			set
			{
				if ((this._CountCitizens != value))
				{
					this.OnCountCitizensChanging(value);
					this.SendPropertyChanging();
					this._CountCitizens = value;
					this.SendPropertyChanged("CountCitizens");
					this.OnCountCitizensChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_Square", DbType="Int NOT NULL")]
		public int Square
		{
			get
			{
				return this._Square;
			}
			set
			{
				if ((this._Square != value))
				{
					this.OnSquareChanging(value);
					this.SendPropertyChanging();
					this._Square = value;
					this.SendPropertyChanged("Square");
					this.OnSquareChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_Region", DbType="Int NOT NULL")]
		public int Region
		{
			get
			{
				return this._Region;
			}
			set
			{
				if ((this._Region != value))
				{
					if (this._Region1.HasLoadedOrAssignedValue)
					{
						throw new System.Data.Linq.ForeignKeyReferenceAlreadyHasValueException();
					}
					this.OnRegionChanging(value);
					this.SendPropertyChanging();
					this._Region = value;
					this.SendPropertyChanged("Region");
					this.OnRegionChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.AssociationAttribute(Name="Country_MajorCity", Storage="_MajorCities", ThisKey="Id", OtherKey="Country")]
		public EntitySet<MajorCity> MajorCities
		{
			get
			{
				return this._MajorCities;
			}
			set
			{
				this._MajorCities.Assign(value);
			}
		}
		
		[global::System.Data.Linq.Mapping.AssociationAttribute(Name="Region_Country", Storage="_Region1", ThisKey="Region", OtherKey="Id", IsForeignKey=true)]
		public Region Region1
		{
			get
			{
				return this._Region1.Entity;
			}
			set
			{
				Region previousValue = this._Region1.Entity;
				if (((previousValue != value) 
							|| (this._Region1.HasLoadedOrAssignedValue == false)))
				{
					this.SendPropertyChanging();
					if ((previousValue != null))
					{
						this._Region1.Entity = null;
						previousValue.Countries.Remove(this);
					}
					this._Region1.Entity = value;
					if ((value != null))
					{
						value.Countries.Add(this);
						this._Region = value.Id;
					}
					else
					{
						this._Region = default(int);
					}
					this.SendPropertyChanged("Region1");
				}
			}
		}
		
		public event PropertyChangingEventHandler PropertyChanging;
		
		public event PropertyChangedEventHandler PropertyChanged;
		
		protected virtual void SendPropertyChanging()
		{
			if ((this.PropertyChanging != null))
			{
				this.PropertyChanging(this, emptyChangingEventArgs);
			}
		}
		
		protected virtual void SendPropertyChanged(String propertyName)
		{
			if ((this.PropertyChanged != null))
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}
		
		private void attach_MajorCities(MajorCity entity)
		{
			this.SendPropertyChanging();
			entity.Country1 = this;
		}
		
		private void detach_MajorCities(MajorCity entity)
		{
			this.SendPropertyChanging();
			entity.Country1 = null;
		}
	}
	
	[global::System.Data.Linq.Mapping.TableAttribute(Name="dbo.MajorCities")]
	public partial class MajorCity : INotifyPropertyChanging, INotifyPropertyChanged
	{
		
		private static PropertyChangingEventArgs emptyChangingEventArgs = new PropertyChangingEventArgs(String.Empty);
		
		private int _Id;
		
		private string _Name;
		
		private int _CountCitizens;
		
		private int _Country;
		
		private System.Nullable<bool> _Capital;
		
		private EntityRef<Country> _Country1;
		
    #region Extensibility Method Definitions
    partial void OnLoaded();
    partial void OnValidate(System.Data.Linq.ChangeAction action);
    partial void OnCreated();
    partial void OnIdChanging(int value);
    partial void OnIdChanged();
    partial void OnNameChanging(string value);
    partial void OnNameChanged();
    partial void OnCountCitizensChanging(int value);
    partial void OnCountCitizensChanged();
    partial void OnCountryChanging(int value);
    partial void OnCountryChanged();
    partial void OnCapitalChanging(System.Nullable<bool> value);
    partial void OnCapitalChanged();
    #endregion
		
		public MajorCity()
		{
			this._Country1 = default(EntityRef<Country>);
			OnCreated();
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_Id", AutoSync=AutoSync.OnInsert, DbType="Int NOT NULL IDENTITY", IsPrimaryKey=true, IsDbGenerated=true)]
		public int Id
		{
			get
			{
				return this._Id;
			}
			set
			{
				if ((this._Id != value))
				{
					this.OnIdChanging(value);
					this.SendPropertyChanging();
					this._Id = value;
					this.SendPropertyChanged("Id");
					this.OnIdChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_Name", DbType="NVarChar(50) NOT NULL", CanBeNull=false)]
		public string Name
		{
			get
			{
				return this._Name;
			}
			set
			{
				if ((this._Name != value))
				{
					this.OnNameChanging(value);
					this.SendPropertyChanging();
					this._Name = value;
					this.SendPropertyChanged("Name");
					this.OnNameChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_CountCitizens", DbType="Int NOT NULL")]
		public int CountCitizens
		{
			get
			{
				return this._CountCitizens;
			}
			set
			{
				if ((this._CountCitizens != value))
				{
					this.OnCountCitizensChanging(value);
					this.SendPropertyChanging();
					this._CountCitizens = value;
					this.SendPropertyChanged("CountCitizens");
					this.OnCountCitizensChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_Country", DbType="Int NOT NULL")]
		public int Country
		{
			get
			{
				return this._Country;
			}
			set
			{
				if ((this._Country != value))
				{
					if (this._Country1.HasLoadedOrAssignedValue)
					{
						throw new System.Data.Linq.ForeignKeyReferenceAlreadyHasValueException();
					}
					this.OnCountryChanging(value);
					this.SendPropertyChanging();
					this._Country = value;
					this.SendPropertyChanged("Country");
					this.OnCountryChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_Capital", DbType="Bit")]
		public System.Nullable<bool> Capital
		{
			get
			{
				return this._Capital;
			}
			set
			{
				if ((this._Capital != value))
				{
					this.OnCapitalChanging(value);
					this.SendPropertyChanging();
					this._Capital = value;
					this.SendPropertyChanged("Capital");
					this.OnCapitalChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.AssociationAttribute(Name="Country_MajorCity", Storage="_Country1", ThisKey="Country", OtherKey="Id", IsForeignKey=true)]
		public Country Country1
		{
			get
			{
				return this._Country1.Entity;
			}
			set
			{
				Country previousValue = this._Country1.Entity;
				if (((previousValue != value) 
							|| (this._Country1.HasLoadedOrAssignedValue == false)))
				{
					this.SendPropertyChanging();
					if ((previousValue != null))
					{
						this._Country1.Entity = null;
						previousValue.MajorCities.Remove(this);
					}
					this._Country1.Entity = value;
					if ((value != null))
					{
						value.MajorCities.Add(this);
						this._Country = value.Id;
					}
					else
					{
						this._Country = default(int);
					}
					this.SendPropertyChanged("Country1");
				}
			}
		}
		
		public event PropertyChangingEventHandler PropertyChanging;
		
		public event PropertyChangedEventHandler PropertyChanged;
		
		protected virtual void SendPropertyChanging()
		{
			if ((this.PropertyChanging != null))
			{
				this.PropertyChanging(this, emptyChangingEventArgs);
			}
		}
		
		protected virtual void SendPropertyChanged(String propertyName)
		{
			if ((this.PropertyChanged != null))
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}
	}
	
	[global::System.Data.Linq.Mapping.TableAttribute(Name="dbo.Regions")]
	public partial class Region : INotifyPropertyChanging, INotifyPropertyChanged
	{
		
		private static PropertyChangingEventArgs emptyChangingEventArgs = new PropertyChangingEventArgs(String.Empty);
		
		private int _Id;
		
		private string _Name;
		
		private EntitySet<Country> _Countries;
		
    #region Extensibility Method Definitions
    partial void OnLoaded();
    partial void OnValidate(System.Data.Linq.ChangeAction action);
    partial void OnCreated();
    partial void OnIdChanging(int value);
    partial void OnIdChanged();
    partial void OnNameChanging(string value);
    partial void OnNameChanged();
    #endregion
		
		public Region()
		{
			this._Countries = new EntitySet<Country>(new Action<Country>(this.attach_Countries), new Action<Country>(this.detach_Countries));
			OnCreated();
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_Id", AutoSync=AutoSync.OnInsert, DbType="Int NOT NULL IDENTITY", IsPrimaryKey=true, IsDbGenerated=true)]
		public int Id
		{
			get
			{
				return this._Id;
			}
			set
			{
				if ((this._Id != value))
				{
					this.OnIdChanging(value);
					this.SendPropertyChanging();
					this._Id = value;
					this.SendPropertyChanged("Id");
					this.OnIdChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_Name", DbType="NVarChar(50) NOT NULL", CanBeNull=false)]
		public string Name
		{
			get
			{
				return this._Name;
			}
			set
			{
				if ((this._Name != value))
				{
					this.OnNameChanging(value);
					this.SendPropertyChanging();
					this._Name = value;
					this.SendPropertyChanged("Name");
					this.OnNameChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.AssociationAttribute(Name="Region_Country", Storage="_Countries", ThisKey="Id", OtherKey="Region")]
		public EntitySet<Country> Countries
		{
			get
			{
				return this._Countries;
			}
			set
			{
				this._Countries.Assign(value);
			}
		}
		
		public event PropertyChangingEventHandler PropertyChanging;
		
		public event PropertyChangedEventHandler PropertyChanged;
		
		protected virtual void SendPropertyChanging()
		{
			if ((this.PropertyChanging != null))
			{
				this.PropertyChanging(this, emptyChangingEventArgs);
			}
		}
		
		protected virtual void SendPropertyChanged(String propertyName)
		{
			if ((this.PropertyChanged != null))
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}
		
		private void attach_Countries(Country entity)
		{
			this.SendPropertyChanging();
			entity.Region1 = this;
		}
		
		private void detach_Countries(Country entity)
		{
			this.SendPropertyChanging();
			entity.Region1 = null;
		}
	}
}
#pragma warning restore 1591
