from numpy.core import numeric
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import os
import time
import plotly.express as px
from plotly.subplots import make_subplots
import plotly.graph_objects as go
from plotly.offline import download_plotlyjs, init_notebook_mode, iplot
from plotly.graph_objs import *
from seaborn import categorical
import streamlit as st




# GLOBAL DATA BLOCK START
data=pd.DataFrame()
df_cat=pd.DataFrame()
df_cat_num=pd.DataFrame()
df_num=pd.DataFrame()
numerical_col=[]
categorical_col=[]

#GLOBAL DATA BLOCK END







# FUNCTIONS BLOCK START
def data_upload(n):
    df = pd.DataFrame()
    data_file = st.file_uploader("Upload only CSV",type=['csv'],key=n)
    if data_file is not None:
        file_details = {"Filename":data_file.name,"FileType":data_file.type,"FileSize":data_file.size}
        st.write(file_details)
        df = pd.read_csv(data_file)
        st.dataframe(df)
    return df

def load_start():
     for percent_complete in range(100):
         time.sleep(0.0000001)
         my_bar.progress(percent_complete + 1)

def load_exit():
             my_bar.progress(0)



def data_conversion():
    data.rename(columns={' Income ':'Income'},inplace=True)
    data["Dt_Customer"] = pd.to_datetime(data["Dt_Customer"], format='%m/%d/%y')  
    data["Income"] = data["Income"].str.replace("$","").str.replace(",","") 
    data["Income"] = data["Income"].astype(float)





def data_cleaning():
    fig, ax = plt.subplots()
    data.drop(['ID'],axis=1,inplace =True)
    duplicate = data[data.duplicated(subset=None,keep='first')]
    st.markdown("### Actual Data Shape {} \n ### Duplicate Rows {}".format(data.shape,duplicate.shape))
    data.drop_duplicates(inplace=True) 
    st.markdown("### Final Data Shape after removing redundancy {} ".format(data.shape)) 
    st.markdown("### Null Values HeatMap")
    sns.heatmap(data.isnull(),yticklabels=False,cmap='viridis',cbar=False)
    st.write(fig)
    st.markdown("## Median Imputation for Null values")
    data["Income"].fillna(value=data["Income"].median(),inplace=True)
    st.markdown("### Median Imputation complete")
    sns.heatmap(data.isnull(),yticklabels=False,cmap='viridis',cbar=False)
    st.write(fig)



def column_segregation():
    df_cat = data.loc[:,data.dtypes==np.object]
    cat_num = ['Kidhome', 'Teenhome', 'AcceptedCmp3', 'AcceptedCmp4', 'AcceptedCmp5', 'AcceptedCmp1',
       'AcceptedCmp2', 'Response', 'Complain']
    df_cat_num = data[cat_num]
    num = ['Year_Birth','Income','Dt_Customer', 'Recency', 'MntWines', 'MntFruits',
       'MntMeatProducts', 'MntFishProducts', 'MntSweetProducts',
       'MntGoldProds', 'NumDealsPurchases', 'NumWebPurchases',
       'NumCatalogPurchases', 'NumStorePurchases', 'NumWebVisitsMonth']
    df_num = data[num]
    st.markdown("### Categorical columns :\n {} \n ### Categorical numerical columns :\n {}\n ###  numerical columns \n{}".format(df_cat.columns,cat_num,num))


def Exceptionblock():
    st.markdown("----------------------------------------")
    st.markdown("PLEASE CHECK FOR ERROR AND RESTART")
    st.markdown("----------------------------------------")





#   FUNCTIONS BLOCK END

if __name__=='__main__':
    #DATA LOADING AND CLEANING SEC BEGIN
    try:
        st.markdown("# Starting APP")
        my_bar = st.progress(0)
        load_start()
        st.markdown("# Enter The Dataset")
        data = data_upload('1')
        load_exit()
        if not data.empty:
            my_bar = st.progress(0)
            st.markdown("# Data Conversion")
            load_start()
            data_conversion()
            load_exit()
            my_bar = st.progress(0)
            st.markdown("# Data Cleaning")
            load_start()
            data_cleaning()
            load_exit()
            my_bar = st.progress(0)
            st.markdown("# Column Segregation")
            load_start()
            column_segregation()
            load_exit()
    except:    
        st.markdown("----------------------------------------")
        st.markdown("### Thank you for using our App")
        st.markdown("----------------------------------------")
    
    #DATA LOADING AND CLEANING SEC END


    #DATA DESCRPTION SEC BEGIN
    try:
        if not data.empty:
           st.markdown("## DATA DESCRIPTION")
           st.write(data.describe())
    except:
        Exceptionblock()

    #DATA DESCRIPTION SEC END

    # COLUMNS
    numerics = ['int16', 'int32', 'int64', 'float16', 'float32', 'float64']
    numericdata = data.select_dtypes(include=numerics)
    numerical_col=numericdata.columns
    categorical_col=list(set(data.columns)-set(numerical_col))
    # COLUMNS

    #DATA VISUALIZATION SEC BEGIN
    try:
        if not data.empty:
                        st.sidebar.title("Visualizations")
                        # General countplot for numeric data
                        st.sidebar.markdown("### General Countplots for Categorical columns")
                        if not st.sidebar.checkbox("Hide", True,key="A"):
                            selectplot=st.sidebar.selectbox("Type of plot ",['Bar plot','Pie Chart'],key="B")
                            select=st.sidebar.selectbox("Visualization based on ",categorical_col,key="C")
                            if selectplot=='Bar plot':
                                st.markdown("### Count plot for Categorical Data")
                                fig=px.histogram(data, x=select)
                                st.plotly_chart(fig)
                            else:
                                col_count = data[select].value_counts()
                                col_count = pd.DataFrame({select:col_count.index, 'Number of Customers':col_count.values})
                                fig = px.pie(col_count, values='Number of Customers', names=select)
                                st.plotly_chart(fig)


    except:
        Exceptionblock()
        

